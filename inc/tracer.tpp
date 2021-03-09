template <typename event_T>
Tracer<event_T>::Tracer(const char* prefix, const char* suffix)
{
	output_prefix = prefix;
	my_pid = GetPid();
	trace_suffix = suffix;
	
	size = 1;
	platform_array = new struct barectf_platform_linux_fs_ctx*[size];
	ctx_array = new struct barectf_default_ctx*[size];
	clock_array = new uint64_t[size];
	queue_array = new std::priority_queue<event_T*, std::vector<event_T*>, Compare>[size];
	for(uint32_t i =0; i<size; i++){
		std::stringstream ss; 
		ss << output_prefix << "/CTF_trace/" << my_pid << "_" << trace_suffix << i;
		clock_array[i] = 0;
		platform_array[i] = barectf_platform_linux_fs_init(1024, ss.str().c_str(), 0, 0, 0, &(clock_array[i]));
		ctx_array[i] = barectf_platform_linux_fs_get_barectf_ctx(platform_array[i]);
	}
};

template <typename event_T>
Tracer<event_T>::~Tracer()
{
	for(uint32_t i =0; i<size; i++){
		barectf_platform_linux_fs_fini(platform_array[i]);
	}
	delete[] platform_array;
	delete[] ctx_array;
	delete[] clock_array;
	delete[] queue_array;
};

template <typename event_T>
void Tracer<event_T>::add_stream()
{
	platform_array_t platform_array2 = new struct barectf_platform_linux_fs_ctx*[size + 1];
	ctx_array_t ctx_array2 = new struct barectf_default_ctx*[size + 1];
	uint64_t* clock_array2 = new uint64_t[size + 1];
	std::copy(platform_array, platform_array + size, platform_array2);
	std::copy(ctx_array, ctx_array + size, ctx_array2);
	std::copy(clock_array, clock_array + size, clock_array2);
	delete[] platform_array;
	delete[] ctx_array;
	delete[] clock_array;
	platform_array = platform_array2;
	ctx_array = ctx_array2;
	clock_array = clock_array2;
	for(uint32_t i = 0; i<size; i++){
		(platform_array[i])->clock_addr = &(clock_array[i]);
	}
	std::stringstream ss; 
	ss << output_prefix << "/CTF_trace/" << my_pid << "_" << trace_suffix << size;
	clock_array[size] = 0;
	platform_array[size] = barectf_platform_linux_fs_init(1024, ss.str().c_str(), 0, 0, 0, &(clock_array[size]));
	ctx_array[size] = barectf_platform_linux_fs_get_barectf_ctx(platform_array[size]);
	size++;
};

template <typename event_T>
void Tracer<event_T>::add_queue(){
	queue_array_t queue_array2 = new std::priority_queue<event_T*, std::vector<event_T*>, Compare>[size + 1];
	std::copy(queue_array, queue_array + size, queue_array2);
	delete[] queue_array;
	queue_array = queue_array2;
};

template <typename event_T>
void Tracer<event_T>::callback(uint64_t begin, tracing_function function, event_T* new_event)
{
  uint32_t i = 0;
  while(i < size){
	if(queue_array[i].size() < MAX_SIZE && begin >= clock_array[i]){
		queue_array[i].push(new_event);
		break;
	}
	if(queue_array[i].size() >= MAX_SIZE && begin >= clock_array[i]){
		event_T* old_event = queue_array[i].top();
		queue_array[i].pop();
		clock_array[i] = old_event->time;
		function(old_event, ctx_array[i]);
		delete old_event;
		if(begin >= clock_array[i]){
			queue_array[i].push(new_event);
			break;
		}
	}
	i++;
  }
  if(i==size){
	add_queue();
	add_stream();
	clock_array[size-1] = 0;
	queue_array[size-1].push(new_event);
  }
}

template <typename event_T>
void Tracer<event_T>::flush(tracing_function function)
{
	event_T* event;
	for(uint32_t i =0; i<size; i++){
		while(queue_array[i].size() != 0){
			event = queue_array[i].top();
			queue_array[i].pop();
			clock_array[i] = event->time;
			
			function(event, ctx_array[i]);
			delete event;
		}
	}
}

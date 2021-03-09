import os, sys, re

# API_prof_str header file given as an argument
api_str_hfile = sys.argv[1]
if not os.path.isfile(api_str_hfile):
  print("Error : header not found")
  exit()
  
enum_pattern = re.compile(re.escape(r"enum kfd_api_id_t {"))
enum_entry_pattern = re.compile(r"(\w+) = \d+")
end_object_pattern = re.compile(re.escape(r"};"))

api_args_pattern = re.compile(re.escape(r"inline std::ostream& operator<< (std::ostream& out, const kfd_api_data_pair_t& data_pair) {"))
end_fct_pattern = re.compile(re.escape(r"}"))

switch_pattern = re.compile(r"switch")
case_pattern = re.compile(r"case .*: {")
default_pattern = re.compile(r"default:")
retval_pattern = re.compile(re.escape(r'out << ") = '))
out_replacement_pattern1 = re.compile(re.escape(r'out << ") = "'))
out_replacement_pattern2 = re.compile(r'out << "\) = (\w+)"')


# API declaration map
with open(api_str_hfile, "r") as input_file:
    next_line = input_file.readline()
    while next_line and not(enum_pattern.match(next_line)):
        next_line = input_file.readline()
    
    enum_vector = "static const kfd_api_id_t all_kfd_api_func[] = { \n\t"
    while next_line and not(end_object_pattern.match(next_line)):  
        if(enum_entry_pattern.search(next_line)):
            enum_vector = enum_vector + enum_entry_pattern.search(next_line).group(1) + ",\n\t"
        next_line = input_file.readline()
    enum_vector = enum_vector[0:len(enum_vector)-3]
    enum_vector = enum_vector + "\n};\n\n"
        
    with open("./src/kfd_args_str.cpp", "w") as cpp_file:
    
        cpp_begin = ("#include <roctracer_hsa_aux.h>\n"
                      "#include <kfd_args_str.h>\n"
                      "#include <sstream>\n"
                      "\n")
                    
        cpp_file.write(cpp_begin)
        cpp_file.write(enum_vector)
        
        

        while next_line and not(api_args_pattern.match(next_line)):
            next_line = input_file.readline()
            
        api_args_begin = ("kfd_api_string_pair_t kfd_api_pair_of_args(uint32_t cid, kfd_api_data_t api_data)\n"
                          "{\n"
                          "  std::ostringstream ret;\n"
                          "  std::ostringstream out;\n"
                          "  switch(cid){\n")
                          
        cpp_file.write(api_args_begin)
        
        while next_line and not(case_pattern.search(next_line)):
            next_line = input_file.readline()
        
        while(1):
            if(case_pattern.search(next_line)):
                cpp_file.write(next_line)
                next_line = input_file.readline()
                next_line = input_file.readline()
                while(not(retval_pattern.search(next_line))):
                    cpp_file.write(next_line)
                    next_line = input_file.readline()
                if(out_replacement_pattern1.search(next_line)):
                    next_line = out_replacement_pattern1.sub(r'ret', next_line)
                else:
                    next_line = out_replacement_pattern2.sub(r'ret << "\1"', next_line)
                for i in range(3):
                    cpp_file.write(next_line)
                    next_line = input_file.readline()
                while next_line and not(case_pattern.search(next_line) or default_pattern.search(next_line)):
                    next_line = input_file.readline()
            else:
                for i in range(4):
                    cpp_file.write(next_line)
                    next_line = input_file.readline()
                break
        api_args_end = ("  return kfd_api_string_pair_t(out.str(), ret.str());\n"
                        "}\n\n")
        cpp_file.write(api_args_end)
        
        enum_vector_fct = ("const kfd_api_id_t* kfd_api_table(){\n"
                           "\treturn all_kfd_api_func;\n"
                           "}\n\n")
        cpp_file.write(enum_vector_fct)

        get_size_fct = ("uint32_t GetKFDApiSize() {\n"
                        "\treturn sizeof(all_kfd_api_func)/sizeof(kfd_api_id_t);\n"
                        "}")
        cpp_file.write(get_size_fct)         
sys.exit(0)
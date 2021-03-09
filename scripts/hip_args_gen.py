#Create cpp file for parsing data into strings
import os, sys, re

# API_prof_str header file given as an argument
api_str_hfile = sys.argv[1]
if not os.path.isfile(api_str_hfile):
  print("Error : header not found")
  exit()

#Regex patterns for finding and replacing specific lines
enum_pattern = re.compile(re.escape(r"enum hip_api_id_t {"))
enum_entry_pattern = re.compile(r"(\w+) = \d+")
end_object_pattern = re.compile(re.escape(r"};"))

api_args_pattern = re.compile(re.escape(r"const char* hipApiString(hip_api_id_t id, const hip_api_data_t* data) {"))
end_fct_pattern = re.compile(re.escape(r"}"))

switch_pattern = re.compile(r"switch")
case_pattern = re.compile(r"case .*:")
default_pattern = re.compile(r"default:")
break_str = re.compile('break;')
first_arg = re.compile(r'(\")(\w+=)(.*\")')
next_arg = re.compile(r'(\", )(\w+=)(.*\")')
parenthesis = re.compile(r'\"\)\";')

#Scripts that will read the hip_prof_str.h file and create an array containing cids and a function for data parsing in a hip_args_str.cpp file
with open(api_str_hfile, "r") as input_file:
    next_line = input_file.readline()
    while next_line and not(enum_pattern.match(next_line)):
        next_line = input_file.readline()
    
    #Collect the cids
    enum_vector = "static const hip_api_id_t all_hip_api_func[] = { \n\t"
    while next_line and not(end_object_pattern.match(next_line)):  
        if(enum_entry_pattern.search(next_line)):
            enum_vector = enum_vector + enum_entry_pattern.search(next_line).group(1) + ",\n\t"
        next_line = input_file.readline()
    enum_vector = enum_vector[0:len(enum_vector)-3]
    enum_vector = enum_vector + "\n};\n\n"

with open(api_str_hfile, "r") as input_file:     
    with open("./src/hip_args_str.cpp", "w") as cpp_file:
    
        cpp_begin = ("#include <roctracer_hip_aux.h>\n"
                     "#include <hip_args_str.h>\n"
                     "#include <sstream>\n"
                     "\n")
                    
        cpp_file.write(cpp_begin)
        
        cpp_file.write(enum_vector) 
        
        while next_line and not(api_args_pattern.match(next_line)):
            next_line = input_file.readline()
        
        #Create the parsing function
        api_args_begin = ("std::string hip_api_arguments(uint32_t cid, hip_api_data_t* data)\n"
                          "{\n"
                          "  std::ostringstream oss;\n"
                          "  switch(cid){\n")
                          
        cpp_file.write(api_args_begin)
        
        while next_line and not(case_pattern.search(next_line)):
            next_line = input_file.readline()
        
        while(1):
            if(case_pattern.search(next_line)):
                cpp_file.write(next_line)
                next_line = input_file.readline()
                next_line = input_file.readline()
                while next_line and not(break_str.search(next_line)):
                    if parenthesis.search(next_line):
                        pass
                    elif next_arg.search(next_line):
                        cpp_file.write(next_arg.sub(r'\1\3', next_line))
                    else : 
                        next_line = first_arg.sub(r'\1\3', next_line)
                        next_line = re.sub(r'<< \"\" <<', '<<', next_line)
                        cpp_file.write(next_line)
                    next_line = input_file.readline()
                cpp_file.write(next_line)
                next_line = input_file.readline()
                while next_line and not(case_pattern.search(next_line) or default_pattern.search(next_line)):
                    next_line = input_file.readline()
            else:
                for i in range(2):
                    cpp_file.write(next_line)
                    next_line = input_file.readline()
                break
        api_args_end = ("  return oss.str();\n"
                        "}\n\n")
        cpp_file.write(api_args_end)
        
        #Function that return the cids array
        enum_vector_fct = ("const hip_api_id_t* hip_api_table(){\n"
                           "\treturn all_hip_api_func;\n"
                           "}\n\n")
        cpp_file.write(enum_vector_fct)
        
        #Function that return the total number of cids
        get_size_fct = ("uint32_t GetHIPApiSize() {\n"
                        "\treturn sizeof(all_hip_api_func)/sizeof(hip_api_id_t);\n"
                        "}")
        cpp_file.write(get_size_fct)        
sys.exit(0)
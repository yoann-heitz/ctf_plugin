#Search the line for clock frequency in config.yaml and replace it with wanted value
import re, os

clock_frequency = os.getenv('CLOCK_FREQUENCY')
if clock_frequency.isdigit():
    with open('./barectf_files/config.yaml', "r+") as f:
        data = f.read()
        f.seek(0)
        f.write(re.sub(r"frequency: [\d]+", r"frequency: " + clock_frequency, data))
        f.truncate()
else :
    print("Error : CLOCK_FREQUENCY isn’t an integer")
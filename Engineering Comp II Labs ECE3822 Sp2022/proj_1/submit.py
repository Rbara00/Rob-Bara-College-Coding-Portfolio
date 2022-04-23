#! /usr/bin/env python

import os
assignment_name = "proj_1"
username = os.getlogin()

# augment the username
studentlist = {}
studentlist["tui86040"]="antonio"
studentlist["tun75924"]="ayensu"
studentlist["tuj22026"]="bara"
studentlist["tuj46346"]="calaman"
studentlist["tui32039"]="christman"
studentlist["tuj23603"]="dong"
studentlist["tuo62954"]="doty"
studentlist["tui14394"]="harron"
studentlist["tup30776"]="high"
studentlist["tuj79145"]="koci"
studentlist["tuf29489"]="lewis"
studentlist["tuk97796"]="love"
studentlist["iobeid_foo"]="obeid"
studentlist["tuj01640"]="ryan"

# username_augmented = username + "_" + studentlist[username]
username_augmented = studentlist[username]  + "_" + username

target_dir = "/data/courses/ece_3822/current/submissions/" + assignment_name + "/" + username_augmented

# create the target directory
if not os.path.isdir(target_dir):
    os.system("mkdir " + target_dir)

# run the rsync commands
submit_command = "find . -type f -not -executable | rsync -v --files-from=- --exclude=""*.o"" --exclude="".*"" --exclude=""submit.py"" --exclude=""*.txt"" . " + target_dir + "/."
os.system(submit_command)

submit_command = "find . -type f ""*.py"" | rsync -v --files-from=- --exclude="".*"" --exclude=""submit.py"" --exclude=""*.txt"" . " + target_dir + "/."
os.system(submit_command)

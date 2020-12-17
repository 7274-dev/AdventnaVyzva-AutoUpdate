import subprocess, time, os

class UtilMan:
    def __init__(self, time):
        self.time = time
        if os.geteuid() != 0:
            exit("You need to have root privileges to run this script.\nPlease try again, this time using 'sudo'. Exiting.")
        else: print("Starting Daemon service")

    def Update(self):
        while True:
            updt = subprocess.call("./deploy.sh")
            time.sleep(self.time)
        
utils = UtilMan()

utils.Update
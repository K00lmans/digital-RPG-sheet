from time import sleep
from github import Github

g = Github()
REPOSITORY = "K00lmans/digital-RPG-sheet"

def get_current_version():
    return g.get_repo(REPOSITORY).get_latest_release().title

if __name__ == "__main__":  # For testing of just this python file
    print(get_current_version())
    sleep(10)

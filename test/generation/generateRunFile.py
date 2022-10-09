import sys
import os
import json

def generateRunFiles(manifestPath : str, outputFile : str):
    data = {}

    with open(manifestPath) as manifestFile:
        data = json.load(manifestFile)

    root = data["root"]
    runDir = f"{root}/{data['runDir']}"

    dirs = []

    for srcSubDir in data["directories"]:
        dirs.append(f"{root}/{srcSubDir}")

    filePaths = []
    for dir in dirs:
        try:
            for filename in os.listdir(dir):
                if filename.endswith(".c"):
                    filePaths.append(f"{dir}/{filename}")

        except:
            continue

    escape = " ^\n\t"

    with open(f"debug.bat","w") as debugFile:
        buildFile.write(f"""gcc -o {runDir}/{outputFile}{escape}{escape.join(filePaths)}
cd {runDir}""")

    with open(f"run.bat", "w") as runFile:
        runFile.write(f"""gcc -o {runDir}/{outputFile}{escape}{escape.join(filePaths)}
cd {runDir}
{runDir}/{outputFile}
cd {os.getcwd()}
pause""")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Run format: python generateRunFile.py <MANIFESTPATH> <OUTPUTFILE>")
        exit()
    generateRunFiles(sys.argv[1], sys.argv[2])
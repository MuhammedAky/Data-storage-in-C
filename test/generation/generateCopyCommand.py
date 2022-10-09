import sys
import os
import json

def generateCopyCommand(manifestPath : str):
    data = {}
    completeManifestPath = None

    with open(manifestPath) as manifestFile:
        data = json.load(manifestFile)

    root = data["dstRoot"]

    newline = "\n"
    backslash = "\\"

    copyCommand = f"cd {root}{newline}"

    for item in data["copyManifest"]:
        for file in item["inclusions"]:
            inPath = f"{item['src']}/{file}"

        lastIdx = -1
        for i in range(len(file) - 1, -1, -1):
            if (file[i] == "/"):
                lastIdx = i
                break
        if (lastIdx > 0):
            file = f"/{file}"

        outPath = f"{root}/{item['dst']}{file[:lastIdx+1]}"
        copyCommand += f"xcopy \"{inPath.replace('/', backslash)}\" \"{outPath.replace('/', backslash)}\" /i /y{newline}"

    # navigate to current directory after done
    copyCommand += f"cd {os.getcwd()}"

    with open("copyFiles.bat", "w") as outFile:
        outFile.write(copyCommand)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Run format: python generateCopyCommand.py < MANIFESTPATH")
        exit()

    generateCopyCommand(sys.argv[1])
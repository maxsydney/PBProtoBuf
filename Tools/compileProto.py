"""
Compile all protobuf definitions to generated cpp headers
"""

import os
import glob
import subprocess
from pathlib import Path
import argparse

def compileSingleFile(protoFile):
    """
    Compile a single .proto file in lib/PBProtoBuf/Generated/Proto into the corresponding 
    cpp header file in lib/PBProtoBuf/Generated
    """

    # TODO: Add a check here that the correct virtual env is active
    
    # Check PBPATH exists
    if os.environ.get('PBPATH') == None:
        raise ValueError("PBPATH variable is not set")

    # If .proto extension doesn't exist, add it
    name, extension = os.path.splitext(protoFile)
    if extension == '':
        extension = '.proto'
    elif not extension == '.proto':
        raise ValueError(f"File {protoFile} is not a .proto file")

    # protoFile = os.path.join(os.environ.get("PBPATH"), "lib/PBProtoBuf", "Proto", name + extension)
    protoFile = name + extension

    print(f"Compiling {protoFile}")

    # Generate the protobuf header
    workingDir = os.path.join(os.environ.get("PBPATH"), "lib/EmbeddedProto")
    protoPath = os.path.join(os.environ.get("PBPATH"), "lib/PBProtoBuf/Proto")
    pluginPath = os.path.join(os.environ.get("PBPATH"), "lib/EmbeddedProto/protoc-gen-eams")
    eamsOutPath = os.path.join(os.environ.get("PBPATH"), "lib/PBProtoBuf/Generated")

    os.chdir(workingDir)
    proc = subprocess.run(['protoc', f"--proto_path={protoPath}", f"--plugin={pluginPath}", f"--eams_out={eamsOutPath}", protoFile])
    if proc.returncode == 0:
        print("Success")
    else:
        print("Compilation failed")


def compileAll():
    """
    Fetch all .proto files in lib/PBProtoBuf/Generated/Proto and compile them into
    cpp headers in lib/PBProtoBuf/Generated
    """

    # Check PBPATH exists
    if os.environ.get('PBPATH') == None:
        raise ValueError("PBPATH variable is not set")

    protoPath = os.path.join(os.environ.get("PBPATH"), "lib/PBProtoBuf/Proto/*.proto")
    for file in glob.glob(protoPath):
        protoFile = Path(file).name
        compileSingleFile(protoFile)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-a", "--all", help="Compile all .proto files", action="store_true")
    parser.add_argument("-n", "--name", type=str, help="Name of .proto file to compile")
    args = parser.parse_args()

    if args.all:
        compileAll()
    else:
        if args.name:
            compileSingleFile(args.name)
        else:
            print("Please pass the name of a .proto file to compile, or use the --all flag")

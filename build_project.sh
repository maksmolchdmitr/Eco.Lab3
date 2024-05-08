#!/usr/bin/env bash
DIR=$(cd "$(dirname "$0")"; pwd)
cd AssemblyFiles/Linux/gcc_7_4_0
bash build.sh || exit 1
echo "Build success!"
cd "$DIR"
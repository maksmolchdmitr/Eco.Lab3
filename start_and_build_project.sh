#!/usr/bin/env bash
DIR=$(cd "$(dirname "$0")"; pwd)
bash build_project.sh && cd BuildFiles/Linux/x64/StaticDebug || echo "Build Failed!"
./EcoLab1
cd "$DIR"
#!/usr/bin/env python

import argparse
import sys
import subprocess

parser = argparse.ArgumentParser()
parser.add_argument("-n", default="100")
parser.add_argument("src", nargs=1)
args = parser.parse_args()
cmd = ["~/comp/dcj_linux/dcj.sh", "test", "--source", args.src[0], "--nodes", args.n]
print " ".join(cmd)
exit_code = subprocess.call(" ".join(cmd), shell=True)
sys.exit(exit_code)

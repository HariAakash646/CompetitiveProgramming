#!/bin/bash

problem=tree
memory=1048576  # 1GB
stack_size=1048576  # 1GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
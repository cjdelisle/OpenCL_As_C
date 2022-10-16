# OpenCL as C

This is a toy project to show how you can, in principle, mix OpenCL code into a C project.

**NOTE**: Requires clang, this will not work with gcc at all.

To try it out:

```bash
make
./thing
```

Env:

* CLFLAGS: cflags for the opencl compilation - If you're on recent amd64: `-march=native -mavx2`
* CFLAGS: cflags for C compilation
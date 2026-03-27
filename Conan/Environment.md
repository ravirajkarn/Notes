---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-03 10:46::27 AM
tags:
  - Conan
  - Cpp
  - python
---

# Environment
## Introduction
`Environment`, In simple Environment variable. This class help in setting virtual environment for out cpp project just like in python if wou are familial with it.

## Variable declaration
```python
from conan.tools.env import Environment

def generate(self):
    env = Environment()
    env.define("MYVAR1", "MyValue1")  # Overwrite previously existing MYVAR1 with new value
    env.append("MYVAR2", "MyValue2")  # Append to existing MYVAR2 the new value
    env.prepend("MYVAR3", "MyValue3") # Prepend to existing MYVAR3 the new value
    env.remove("MYVAR3", "MyValue3")  # Remove the MyValue3 from MYVAR3
    env.unset("MYVAR4")               # Remove MYVAR4 definition from environment

    # And the equivalent with paths
    env.define_path("MYPATH1", "path/one")  # Overwrite previously existing MYPATH1 with new value
    env.append_path("MYPATH2", "path/two")  # Append to existing MYPATH2 the new value
    env.prepend_path("MYPATH3", "path/three") # Prepend to existing MYPATH3 the new value
```

## Generation of environment files

The generation of environment script files (like `envfile.bat|.sh|.ps1|.env`) can be done indirectly by the `EnvVars` class, which can be obtained with:
```python
from conan.tools.env import Environment

env1 = Environment()
...
envvars = env1.vars(self)  # An EnvVars object
# Generate a .bat|.sh|.ps1|.env file depending on current
# settings and Conan configuration
envars.save_script("mybuild")
# or decide to be explicit and generate some of the files:
envvars.save_dotenv("myenv.env")
```

> [!tip]
> These files can be used also automatically by subsequent `self.run()` calls. For more information see the `EnvVars` class documentation.

## Priority

Environments can be composed:

```python
from conan.tools.env import Environment

env1 = Environment()
env1.define(...)
env2 = Environment()
env2.append(...)

env1.compose_env(env2) # env1 has priority, and its modifications will prevail
```
## Obtaining environment variables[¶](https://docs.conan.io/2/reference/tools/env/environment.html#obtaining-environment-variables "Link to this heading")

You can obtain an `EnvVars` object with the `vars()` method like this:

```python
from conan.tools.env import Environment

def generate(self):
    env = Environment()
    env.define("MYVAR1", "MyValue1")
    envvars = env.vars(self, scope="build")
    # use the envvars object
```

> [!important]
> The default `scope` is equal `"build"`, which means that if this `envvars` generate a script to activate the variables, such script will be automatically added to the `conanbuild.sh|bat` one, for users and recipes convenience. Conan generators use `build` and `run` scope, but it might be possible to manage other scopes too.

# VirtualRunEnv
`VirtualRunEnv` is a generator that produces a launcher _conanrunenv_ .bat, .ps1 or .sh script containing environment variables of the run time environment.

The launcher contains the runtime environment information, anything that is necessary in the environment to actually run the compiled executables and applications. The information is obtained from:

- The `self.runenv_info` of the dependencies corresponding to the `host` context.
- Also automatically deduced from the `self.cpp_info` definition of the package to define `PATH`.
- `LD_LIBRARY_PATH`, `DYLD_LIBRARY_PATH`, and `DYLD_FRAMEWORK_PATH` are similarly deduced on non-Windows hosts if the `os` setting is set.

```python
from conan import ConanFile
from conan.tools.env import VirtualRunEnv

class Pkg(ConanFile):
    settings = "os", "compiler", "arch", "build_type"
    requires = "zlib/1.3.1", "bzip2/1.0.8"

    def generate(self):
        ms = VirtualRunEnv(self)
        ms.generate()
```

> [!warning]
> We need to manually run the `conanrun.sh`
> ```bash
> source build/Release/generators/conanrun.sh
> ```

# VirtualBuildEnv
VirtualBuildEnv is a generator that produces a _conanbuildenv_ .bat, .ps1 or .sh script containing the environment variables of the build time context:
- From the `self.buildenv_info` of the direct `tool_requires` in “build” context.
- From the `self.runenv_info` of the transitive dependencies of those `tool_requires`.
```python
from conan import ConanFile
from conan.tools.env import VirtualBuildEnv

class Pkg(ConanFile):
    settings = "os", "compiler", "arch", "build_type"
    requires = "zlib/1.3.1", "bzip2/1.0.8"

    def generate(self):
        ms = VirtualBuildEnv(self)
        ms.generate()
```

Note that instantiating the `VirtualBuildEnv()` generator without later calling the `generate()` method, which is intended only for the `generate()` recipe method, will inhibit the creation of environment files.

So something like:
```python
ms = VirtualBuildEnv(self)
my_env_var = ms.vars().get("MY_ENV_VAR")
# does not create conanbuildenv.sh|.bat files
```
will stop creating the `conanbuild.sh|.bat` and `conanbuildenv.sh|.bat` files that are created by default, even when `VirtualBuildEnv` is not instantiated.

In order to keep creating those files, the `auto_generate=True` argument can be passed to the constructor, as:
```python
ms = VirtualBuildEnv(self, auto_generate=True)
my_env_var = ms.vars().get("MY_ENV_VAR")
# does create conanbuildenv.sh|.bat files
```
> [!warning]
> We need to manually run the `conanbuild.sh`
> ```bash
> source build/Release/generators/conanbuld.sh
> ```



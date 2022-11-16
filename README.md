# Prova intermedia di programmazione

#### *Segmentation Fault (core dumped)*

### 1. How to Compile:

**In main directory**

- Launch `cmake . -B <cmake-configuration-folder>`. This will create the cmake configuration folder. Note: this can't be
  named `bin`
- Run `cmake --build <cmake-configuration-folder>`. This will create a `bin` folder and will build the actual executable

At the end of the process you should be in a very similar situation

```
<Project Folder>
│   README.md
│   .gitignore
│   CMakeLists.txt    
│
└───include
│   │   ...
│
└───src
│   │   ...
│   
└───<cmake-configuration-folder>
│   │   ...
│
└───bin
│   │   <executable>
│   
```


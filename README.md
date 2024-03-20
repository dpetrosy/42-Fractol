<a name="readme-top"></a>
<div align="center">
  <!-- Logo -->
  <a href="https://github.com/dpetrosy/42-Fractol">
  <img src="README_files/logo.png" alt="Logo" width="80" height="80">
  </a>

  <!-- Project Name -->
  <h1>Fractol Project</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>42 Yerevan Fractol</b><br>
	  For further information about 42cursus and its projects, please refer to <a href="https://github.com/dpetrosy/42cursus"><b>42cursus repo</b></a>.
  </p>

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/dpetrosy/42-Fractol?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/dpetrosy/42-Fractol?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/dpetrosy/42-Fractol?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/dpetrosy/42-Fractol?style=for-the-badge" />
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-mandatory-part">🔷 Mandatory Part</a>
    <span> · </span>
	  <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

> One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of \
> an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller \
> scales. This project uses the school's graphical library, MiniLibX.

For detailed information, refer to the [**subject of this project**](README_files/fractol_subject.pdf).

	🚀 TLDR: The fract-ol project from the 42 School is one of the three "beginner" graphical 
 		 projects of the cursus. It teaches you about manipulating a low-level graphic library,
   		 advanced math, and more.

## 🔷 Mandatory Part

The program `pipex` should repeat the behavior of the next shell command:
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```

> [!NOTE]  
> All errors like: wrong commands,  permission to files and etc are handled.

## 🌟 Bonus Part

Program needs to handle multiple pipes:
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```

and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path/to/pipex && make
```

**2. How to run the program**

Run the executable with commands of your choice:
```shell
./pipex input "cat" "wc -l" output
```

Use `clean` to delete all object files, `fclean` to remove executable and all object files, and `re` to recompile the program:
```shell
make clean / make fclean / make re
```

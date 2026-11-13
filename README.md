# C++ Modules

Modules 00 to 09 of the 42 C++ curriculum, done at 1337 School: 38 small exercises that go from a first class to templates and the STL.

Everything is written in C++98 and compiles with `-Wall -Wextra -Werror -std=c++98`.

## Modules

| Module | Topic |
| --- | --- |
| [cpp00](cpp00) | Classes, member functions, streams, static and const members |
| [cpp01](cpp01) | Stack and heap allocation, references, pointers to member functions, file streams |
| [cpp02](cpp02) | Orthodox Canonical Form, operator overloading, fixed-point numbers |
| [cpp03](cpp03) | Inheritance, including the diamond problem |
| [cpp04](cpp04) | Polymorphism, abstract classes, interfaces, deep copies |
| [cpp05](cpp05) | Exceptions |
| [cpp06](cpp06) | C++ casts |
| [cpp07](cpp07) | Function and class templates |
| [cpp08](cpp08) | STL containers, iterators and algorithms |
| [cpp09](cpp09) | The STL in practice: `std::map`, `std::stack`, `std::vector`, `std::list` |

## Build and run

Each exercise has its own folder and its own Makefile.

```sh
git clone https://github.com/mfk-ayoub/cpp-module.git
cd cpp-module/cpp00/ex00
make
./megaphone hello world
```

| Command | What it does |
| --- | --- |
| `make` | Builds the program (object files go in `bin/`) |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and the program |
| `make re` | Rebuilds from scratch |
| `make debug` | Rebuilds with debug symbols for gdb |

You need `make` and a C++ compiler available as `c++`.

## Exercises

The second column is the name of the program that `make` builds.

### cpp00: classes and streams

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `megaphone` | Prints its arguments in upper case. |
| ex01 | `phonebook` | An interactive phone book with the commands `ADD`, `SEARCH` and `EXIT`. It keeps 8 contacts and replaces the oldest one when full. |
| ex02 | `account` | Rebuilds a lost `Account.cpp` from its header and a log file, so that the output of the given tests matches the log. |

### cpp01: memory, references and pointers to members

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `zombie` | Creates one zombie on the heap and one on the stack, to show who has to delete what. |
| ex01 | `zombieHorde` | Allocates a horde of N zombies in a single allocation. |
| ex02 | `pointer` | Reaches the same string through a pointer and through a reference. |
| ex03 | `Weapon` | Two humans share a weapon: one holds a reference to it, the other a pointer that may be empty. |
| ex04 | `replace` | `./replace <file> <s1> <s2>` writes `<file>.replace`, a copy of the file where every `s1` becomes `s2`. |
| ex05 | `Harl` | Calls the right complaint (debug, info, warning, error) through pointers to member functions, with no chain of `if`. |
| ex06 | `harlFilter` | `./harlFilter <LEVEL>` prints that level and every level above it, using a `switch`. |

### cpp02: canonical form and operators

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `Fixed` | A fixed-point number class in Orthodox Canonical Form: default constructor, copy constructor, assignment operator, destructor. |
| ex01 | `Fixed` | Adds construction from an int or a float, conversion back, and the `<<` operator. |
| ex02 | `Fixed` | Adds the comparison, arithmetic, increment and decrement operators, and `min` and `max`. |
| ex03 | `BSP` | Uses the class to tell whether a point lies inside a triangle. |

### cpp03: inheritance

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `ClapTrap` | A base class that can attack, take damage and repair itself. |
| ex01 | `ScavTrap` | A class derived from ClapTrap, to show the order of construction and destruction. |
| ex02 | `FragTrap` | A second derived class. |
| ex03 | `DiamondTrap` | Inherits from both ScavTrap and FragTrap. Virtual inheritance keeps a single ClapTrap inside it. |

### cpp04: polymorphism

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `Animal` | Dog and Cat override a virtual `makeSound`. WrongAnimal and WrongCat show what happens without `virtual`. |
| ex01 | `Brain` | Each animal owns a Brain of 100 ideas, so copies have to be deep copies. |
| ex02 | `Abstract` | Animal becomes an abstract class that cannot be instantiated. |
| ex03 | `IceCure` | Interfaces and an abstract class: a Character equips Ice and Cure materias created by a MateriaSource. |

### cpp05: exceptions

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `Bureaucrat` | A bureaucrat with a grade from 1 to 150. Going out of range throws `GradeTooHighException` or `GradeTooLowException`. |
| ex01 | `Form` | A form that a bureaucrat can sign only with a high enough grade. |
| ex02 | `BureaucratAForm` | The form becomes abstract, with three concrete forms to execute: one writes ASCII trees to `<target>_shrubbery`, one robotomizes its target half of the time, one grants a presidential pardon. |
| ex03 | `BureaucratAForm` | An Intern creates any of the three forms from its name. |

### cpp06: casts

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `convert` | `./convert <literal>` detects whether the literal is a char, an int, a float or a double, and prints it in all four types. |
| ex01 | `Serializer` | Turns a pointer into an integer and back with `reinterpret_cast`. |
| ex02 | `RTTI` | Finds the real type behind a base class pointer or reference with `dynamic_cast`. |

### cpp07: templates

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `whatever` | Function templates `swap`, `min` and `max`. |
| ex01 | `iter` | A function template that applies a function to every element of an array. |
| ex02 | `Array` | A class template `Array<T>` with deep copies, `size()` and an index operator that throws when out of range. |

### cpp08: the STL

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `easyfind` | Finds an integer in any container with `std::find`. |
| ex01 | `Span` | Stores up to N integers and returns the shortest and the longest distance between two of them. |
| ex02 | `MutantStack` | A `std::stack` that can be iterated. |

### cpp09: the STL in practice

| Exercise | Program | What it does |
| --- | --- | --- |
| ex00 | `btc` | `./btc <file>` reads lines of `date \| value` and prints each value multiplied by the bitcoin price on that date. Prices come from `data.csv`, loaded into a `std::map`; a date with no price uses the closest earlier one. Bad dates, negative values and values above 1000 are reported line by line. Run it from its own folder, where `data.csv` is. |
| ex01 | `RPN` | `./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"` evaluates an expression in reverse Polish notation with a `std::stack`. |
| ex02 | `PmergeMe` | `./PmergeMe 3 5 9 7 4` sorts positive integers with the merge-insertion (Ford-Johnson) algorithm, once in a `std::vector` and once in a `std::list`, and prints the time each one took. |

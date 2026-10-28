# Assignment 12: Type Casting and Casting Operators in C++

## About the Program

This C++ program demonstrates **type casting**, which means converting a value from one data type to another. It shows implicit conversion, C-style conversion and the four C++ casting operators.

| Cast | Use in the program |
|---|---|
| Implicit conversion | `float f = a;` (compiler converts int to float automatically) |
| C-style cast | `(int)pi` converts 3.14 to 3 |
| `static_cast` | `static_cast<float>(a) / b` gives a decimal result instead of integer division |
| `const_cast` | Removes `const` from a pointer so the value can be changed |
| `dynamic_cast` | Safely casts an `Animal*` to `Dog*` (works) and `Cat*` (fails, returns `nullptr`) |
| `reinterpret_cast` | Views the memory of an `int` as `char` |

## Program Flow

1. **Implicit and C-style:** The int `a` is converted to float automatically, and `(int)3.14` gives 3 (decimal part is lost).
2. **static_cast:** Shows `a / b` without a cast (integer division) and with `static_cast<float>` (correct decimal result).
3. **const_cast:** A `const int*` is converted to `int*` and the value of `x` is changed from 10 to 20.
4. **dynamic_cast:** An `Animal*` pointing to a `Dog` object is cast to `Dog*` (success) and to `Cat*` (fails and returns `nullptr`).
5. **reinterpret_cast:** The address of the int 65 is treated as `char*`, so the first byte is shown as the character `A`.

## Files

| File | Description |
|---|---|
| `assi12.cpp` | C++ source code |
| `README.md` | Project description |

## How to Compile and Run

Requirement: a C++ compiler (g++) or Visual Studio Code with a C++ setup.

```bash
g++ assi12.cpp -o assi12
./assi12
```

On Windows PowerShell use `.\assi12` to run.

## Sample Input and Output

**Input:**

```
7 2
```

**Output:**

```
Enter two integers: 
--- 1. Implicit and C-style Casting ---
Implicit : int 7 becomes float 7
C-style  : (int)3.14 = 3

--- 2. static_cast ---
Without cast : 7 / 2 = 3
With cast    : 7 / 2 = 3.5

--- 3. const_cast ---
x after const_cast = 20

--- 4. dynamic_cast ---
Cast to Dog successful: Dog fetches the ball
Cast to Cat failed (nullptr returned)

--- 5. reinterpret_cast ---
First byte of 65 seen as char = A
```

## Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| 1 | `7 2` | Without cast 3, with cast 3.5; x = 20; Dog cast successful, Cat cast failed; first byte = A |
| 2 | `9 4` | Without cast 2, with cast 2.25; x = 20; Dog cast successful, Cat cast failed; first byte = A |

## Important Points

- `dynamic_cast` needs a base class with at least one `virtual` function.
- `dynamic_cast` returns `nullptr` for a wrong pointer cast (and throws `bad_cast` for a reference).
- Changing a value through `const_cast` is safe only if the original object was not declared `const`.
- `reinterpret_cast` is dangerous and system dependent. The `A` output appears on little-endian systems (normal PCs).
- C++ casts are safer and easier to search than C-style casts.

## Learning Outcomes

- Convert values using implicit and explicit casting.
- Use `static_cast` to avoid wrong results like integer division.
- Use `const_cast` and `dynamic_cast` correctly.
- Understand the risk of `reinterpret_cast`.

## Repository Details

- **Repository:** https://github.com/YOUR_USERNAME/Assignment12
- **Branch:** main

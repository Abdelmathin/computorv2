<p align="center">
    <a href="" target="_blank">
        <img style="border-radius: 40px;" src="docs/assets/img/computorv2.png" width="200" alt="Computor V2 Logo" />
    </a>
</p>

<p align="center">
    <strong>Welcome to Computor V2!</strong>
    <br>
    This repository contains a powerful shell that allows for the assignment of variables, including complex numbers, matrices, polynomials, vectors, and regular numeric values. The shell can perform operations between these types and return the results seamlessly. It supports various mathematical functions, enabling users to assign and manipulate variables for complex calculations.
</p>

<p align="center">
    <a href="https://abdelmathin.github.io/42attachments/subjects/en//42subjects-computorv1.pdf" target="_blank">
        <img src="https://img.shields.io/badge/github-abdelmathin-red" alt="Subject" />
    </a>
    <a href="#">
        <img src="https://img.shields.io/badge/version-v1.0.0-blue" alt="Version" />
    </a>
    <a href="https://paypal.me/abdelmathin" target="_blank">
        <img src="https://img.shields.io/badge/Donate-PayPal-ff3f59.svg" alt="Donate" />
    </a>
</p>

## Objectives

- **Variable Assignment:** Enable users to assign values to polynomials, functions, matrices, vectors, and complex numbers.
- **Mathematical Operations:** Support basic arithmetic operations and allow calculations between various types of variables.
- **Integrate Mathematical Functions:** Create a tool that integrates mathematical functions and performs operations with different types of variables.
- **Derivative Calculation:** Implement functionality to compute the derivative of functions and analyze rates of change.
- **Matrix Operations:** Facilitate matrix operations such as addition, multiplication, and finding determinants.
- **Complex Number Support:** Allow users to perform arithmetic operations with complex numbers, including real and imaginary components.
- **Higher-Order Derivatives:** Enable the computation of higher-order derivatives for in-depth function analysis.

## Prerequisites

- Ensure you have `make` and a compatible compiler (like `gcc` or `clang`) installed on your system.

## Installation

1. **Clone the Repository:**
    ```bash
    git clone git@github.com:Abdelmathin/computorv2.git
    ```

2. **Navigate to the Project Directory:**
    ```bash
    cd computorv2
    ```

3. **Build the Project:**
    ```bash
    make
    ```

## Usage

To run the shell, execute the following command:

```bash
./computor


### Examples

Here’s a simple examples of how to use the shell:

1. **Assign a polynomial:**

	In this example, a polynomial p is assigned, which is a quadratic function. The coefficients 2, 3, and 5 represent the constants for x<sup>2</sup>, x, and the constant term, respectively.

	This polynomial can be used for further calculations, evaluations, and derivative computations.

	```bash
	p = 2*x^2 + 3*x + 5
	```

2. **Assign a function:**

	Here, a function g(x) is defined, which combines a trigonometric function, the sine of x, multiplied by x, and the natural logarithm of x + 2i.

	This showcases the shell's ability to handle both real and complex functions, providing a powerful tool for mathematical analysis.

	```bash
	g(x) = sin(x) * x - ln(x + 2i)
	```

3. **Calculate the derivative:**

	In this step, a new function f(x) is created by adding the sine function to the derivative of g(x).

	This demonstrates the shell's capability to compute derivatives and use them in subsequent functions, allowing for complex mathematical manipulations.

	```bash
	f(x) = sin(x) + g'(x)
	```

4. **Assign a matrix:**

	A matrix M is defined, which is a 2x2 array containing integers.

	This matrix can be used for various operations, such as transformations, multiplications, and more complex linear algebra tasks.

	```bash
	M = [[1, 2], [3, 4]]
	```

5. **Perform a matrix operation:**

	Here, the matrix M is multiplied by itself.

	The shell computes the resulting matrix, demonstrating its ability to handle matrix operations effectively.

	The result will yield a new matrix, which can be used for further calculations or analyses.

	```bash
	result = M * M
	```

6. **Assign a complex number:**

	A complex number c is assigned, which consists of a real part (3) and an imaginary part (4).

	This example showcases the shell's support for complex number calculations, essential for many mathematical applications, particularly in engineering and physics.

	```bash
	c = 3 + 4i
	```

7. **Perform operations with the complex number:**

	In this example, the previously assigned complex number c is added to another complex number 1 + 2i. The shell computes the sum, resulting in a new complex number that combines both real and imaginary parts. This illustrates how users can perform arithmetic operations with complex numbers, enhancing the versatility of the tool.

	```bash
	result = c + (1 + 2i)
	```

8. **Evaluate a polynomial at a specific value:**

	The polynomial p is evaluated at x = 2. The shell computes the result, providing insights into the behavior of the polynomial at that specific point.

	```bash
	value = p(2)
	```


<!--

# Derivative:

- To differentiate
$$ P(x) = a . x^n + b $$
where a, x, n, b are all functions of x, we use the product rule, the chain rule, and the general power rule.



$$
\begin{bmatrix}
 0 & 0 & 0 & 0 \\
 0 & 0 & 0 & 0 \\
 0 & 0 & 0 & 0 \\
 0 & 0 & 0 & 0 \\
\end{bmatrix}
$$
--->

<!-- $$  P(x) = a . x^n + b $$

$$  \frac{d P(x)}{d x} = \frac{d a}{d x} . x^n + a . \frac{d x^n}{d x} + \frac{d b}{d x} $$
$$ \frac{d x^n}{d x} = $$ -->



<p align="center">
	<a href="" target="blank">
		<img style="border-radius: 40px;" src="docs/assets/img/computorv2.png" width="200" alt="Toast Logo" />
	</a>
</p>

<p align="center">
	This repository contains a powerful shell that allows for the assignment of variables, including complex numbers, matrices, polynomials, vectors, and regular numeric values. The shell can perform operations between these types and return the result seamlessly. It supports various mathematical functions, enabling the user to assign and manipulate variables for complex calculations.
</p>

<p align="center">
		<a href="https://abdelmathin.github.io/42attachments/subjects/en//42subjects-computorv1.pdf" target="_blank">
			<img src="https://img.shields.io/badge/subject-pdf-red" alt="Subject"/>
		</a>
		<a href="#">
			<img src="https://img.shields.io/badge/version-v1.0.0-blue" alt="Discord"/>
		</a>
		<!-- <a href="https://discord.gg/Xvqyc33KRR" target="_blank">
			<img src="https://img.shields.io/badge/discord-online-brightgreen.svg" alt="Discord"/>
		</a>
		<a href="https://twitter.com/abdelmathin" target="_blank">
			<img src="https://img.shields.io/badge/twitter-online-brightgreen.svg">
		</a> -->
		<a href="https://paypal.me/abdelmathin" target="_blank">
			<img src="https://img.shields.io/badge/Donate-PayPal-ff3f59.svg"/>
		</a>
</p>

## Objectives:

- Enable users to assign polynomial expressions, allowing for the representation of mathematical equations.

- Facilitate the assignment of functions, including the ability to incorporate trigonometric and logarithmic functions with complex numbers.

- Implement functionality to calculate the derivative of assigned functions, enabling users to analyze rates of change and function behavior.

- Allow for the assignment of matrices, providing a structured way to represent and manipulate data.

- Support matrix operations, such as multiplication, enabling users to perform linear algebra calculations seamlessly.

- Enable the assignment of complex numbers, allowing for calculations that involve real and imaginary components.

- Facilitate operations with complex numbers, allowing users to perform arithmetic operations and combinations with other numerical types.

- Create a tool that integrates mathematical functions and is capable of performing operations with variables of different types.

- Implement functionality to compute derivatives of functions, allowing for the analysis of rates of change and other calculus-related operations.

- Allow users to compute higher-order derivatives, facilitating deeper exploration of function behavior and characteristics.

```bash
pip install computorv2
```

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

## Usage:

To run the shell, execute the following command:

```bash
./computor
```

### Example

Here’s a simple example of how to use the shell:

1. **Assign a polynomial:**
```bash
p = 2*x^2 + 3*x + 5
```
In this example, a polynomial p is assigned, which is a quadratic function. The coefficients 2, 3, and 5 represent the constants for x <sup>2</sup>, x, and the constant term, respectively. This polynomial can be used for further calculations, evaluations, and derivative computations.

2. **Assign a function:**
```bash
g(x) = sin(x) * x - ln(x + 2i)
```

3. **Calculate the derivative:**
```bash
f(x) = sin(x) + g'(x)
```

4. **Assign a matrix:**
```bash
M = [[1, 2], [3, 4]]
```

5. **Perform a matrix operation:**
```bash
result = M * M
```

6. **Assign a complex number:**
```bash
c = 3 + 4i
```

7. **Perform operations with the complex number:**
```bash
result = c + (1 + 2i)
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



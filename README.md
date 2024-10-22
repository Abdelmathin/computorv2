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

- Develop a command-line shell that allows the assignment of variables: complex numbers, matrices, polynomials, vectors, and numeric values.

- Implement operations between these types, including addition, subtraction, multiplication, and more advanced calculations like derivatives.

- Provide support for complex functions, coefficients, and exponents.

- Create a tool that integrates mathematical functions and is capable of performing operations with variables of different types.

- Ensure that the shell can handle matrix and vector operations, complex number manipulations, and polynomial calculations efficiently.

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

## Example

Here’s a simple example of how to use the shell:

1. **Assign a polynomial:**
```bash
p = 2*x^2 + 3*x + 5
```

2. **Calculate the derivative:**
```bash
p'
```

3. **Assign a matrix:**
```bash
M = [[1, 2], [3, 4]]
```

3. **Perform a matrix operation:**
```bash
result = M * M
```

4. **Assign a complex number:**
```bash
c = 3 + 4i
```

5. **Perform operations with the complex number:**
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




# Bulletproofs Demo in C++
## What are Bulletproofs?
Bulletproofs are short non-interactive zero-knowledge proofs that require no trusted setup. A bulletproof can be used to convince a verifier that an encrypted plaintext is well formed. 
They were proposed in 2017 by Buenz et al. at Stanford University as a means to provide confidentiality in Bitcoin. Currently Monero uses Bulletproofs on their main chain.
Bulletproofs can serve as range-proofs or proof of satisfiability of arithmetic circuits. The demo is for range-proofs only.

## Getting Started
### Prerequisites
The project is written in C++, so a C++ compiler is required. Aside from that, the project utilizes [GNU Make](https://www.gnu.org/software/make/) for its build system, and [Boost](https://www.boost.org/) libraries for serialization. 

### Directory Structure
```
.
+-- src
|   +-- tests
|       +-- math_test.cpp
|       +-- prover_test.cpp
|   +-- group.cpp
|   +-- group.hpp
|   +-- inner_product_arg.cpp
|   +-- inner_product_arg.hpp
|   +-- main.cpp
|   +-- prover.cpp
|   +-- prover.hpp
|   +-- serialize.hpp
|   +-- vector_util.cpp
|   +-- vector_util.hpp
|   +-- verifier.hpp
|   +-- verifier.cpp
+-- build
+-- README.md
+-- LICENSE.md
```
### Usage
1. Clone the repository.
```bash
git clone "https://github.com/archit-p/bulletproofs-demo/"
```
2. Build the executable using Make.
```bash
cd bulletproofs-demo/
make
```
4. Run the demo.
```bash
./build/demo
```

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgements
This project was carried out at the [Computer Architecture and Systems Lab, Indian Institute of Science](https://drona.csa.iisc.ac.in/~casl/) under the supervision of [Prof. K. Gopinath](https://www.csa.iisc.ac.in/~gopi/).

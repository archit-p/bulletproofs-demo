
# Bulletproofs Demo in C++
## What are Bulletproofs?
Bulletproofs are short non-interactive zero-knowledge proofs that require no trusted setup. A bulletproof can be used to convince a verifier that an encrypted plaintext is well formed. 
They were proposed in 2017 by Buenz et al. at Stanford University as a means to provide confidentiality in Bitcoin. Currently Monero uses Bulletproofs on their main chain.
Bulletproofs can serve as range-proofs or proof of satisfiability of arithmetic circuits. The demo is for range-proofs only.

## Dependencies
1. Git
2. GNU Make

## File Structure
All source files are contained in src/ folder.
Build files go to build/ folder.

## How to install and run?
1. git clone "https://github.com/archit-p/bulletproofs-demo/"
2. cd bulletproofs-demo/
3. make
4. ./build/demo

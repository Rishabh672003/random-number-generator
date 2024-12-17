# Random Number Generators

Whenever i learn a new language i try to make a random number generator in it, only catch is the numbers precision
should be arbitrary that is it should be able to generate number of any length.

For now i think the rankings are:

1. Python => the language itself can handle arbitrary precision ints so you dont have to do anything else.
2. Go => the standard library has everything that you need a bigint module as well as a crypto module to generate
   numbers by using bigints
3. Rust => needs external dependency of `num` as well as `rand` still the language is joy to work with
4. C++ => needs external dependency of `boost`

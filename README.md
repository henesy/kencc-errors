# Kencc errors/warnings

The kencc compiler suite, or, the Plan 9 compiler suite are pleasantly simple and non-posix. 

This repository aims to document some potentially misleading or otherwise unintuitive errors/warnings which can be commonplace while using the kencc suite. 

Note that with regular use and some knowledge about how compilers work under the hood may make some of these messages more intuitive. 

These errors/warnings are, if nothing else, usually very literal. 

## Notes

Examples were performed on 9front/amd64.

Examples are provided with the relevant .c/.h files and a .txt file containing a build transcript for reference. 

Mistakes causing the error/warning will be indicated with a comment in the form:

	/* Bad part - {warning, error}
	
		Some explanation
		...
	*/

## Usage

These examples should be built by hand. No mkfile is provided to this end. 

Refer to [2c(1)](http://man.postnix.pw/9front/1/2c) and [2l(1)](http://man.postnix.pw/9front/1/2l) for the correct compiler/arguments regarding a specific platform or build. 

Examples are given in terms of building/running for/on amd64.

	% 6c foo.c
	# Some errors or warnings
	% 6l foo.6
	# Maybe something here, too
	% 6.out

## References

- [2c(1)](http://man.postnix.pw/9front/1/2c)
- [2l(1)](http://man.postnix.pw/9front/1/2l)

# Hunting for compiler errors

### From /sys/src/cmd

	tenshi% gr 'function not declared' .
	…
	./cc/com.c:617: 				diag(n, "function not declared: %F", l);
	tenshi% 

### The context in com.c around line 617

	if(!debug['B']){
		if(l->type->down == T){
			if(!debug['T'])
				nerrors--;
			diag(n, "function not declared: %F", l);
		}else if(l->type->down->etype == TOLD) {
			nerrors--;
			diag(n, "function args not checked: %F", l);
		}
	}


### Then from /sys/src/cmd/cc

	tenshi% g 'diag\(' *.c
	bits.c:69: 	diag(Z, "bad in bnum");
	com.c:72: 		diag(Z, "Z in tcom");
	com.c:81: 		diag(n, "unknown op in type complex: %O", n->op);
	com.c:301: 				diag(n, "inc/dec of a void pointer");
	com.c:553: 				diag(n, "signof bitfield");
	com.c:561: 			diag(n, "signof undefined type");
	com.c:577: 				diag(n, "sizeof bitfield");
	com.c:585: 			diag(n, "sizeof undefined type");
	com.c:589: 			diag(n, "sizeof function");
	com.c:617: 				diag(n, "function not declared: %F", l);
	com.c:620: 				diag(n, "function args not checked: %F", l);
	com.c:628: 			diag(n, "name not declared: %F", n);
	com.c:696: 			diag(n, "address of a bit field");
	com.c:700: 			diag(n, "address of a register");
	com.c:728: 				diag(n, "structure not fully declared %s", t->tag->name);
	com.c:730: 				diag(n, "structure not fully declared");
	com.c:773: 			diag(n, "not enough function arguments: %F", l);
	com.c:792: 		diag(n, "too many function arguments: %F", l);
	com.c:798: 			diag(l, "argument prototype mismatch \"%T\" for \"%T\": %F",
	com.c:850: 		diag(n, "not a member of struct/union: %F", n);
	com.c:866: 		diag(n, "constructor must be a structure");
	com.c:874: 			diag(n, "constructor list too short");
	com.c:900: 		diag(n, "constructor list too long");
	com.c:911: 		diag(n, "not an l-value");
	com.c:1054: 					diag(n, "modulo by zero");
	com.c:1056: 					diag(n, "divide by zero");
	com.c:1061: 					diag(n, "modulo by zero");
	com.c:1063: 					diag(n, "divide by zero");
	com.c:1210: 			diag(n, "divide check");
	com64.c:285: 			diag(n, "unknown vlong %O", n->op);
	com64.c:388: 			diag(n, "unknown %T->vlong cast", l->type);
	com64.c:478: 			diag(n, "unknown vlong->%T cast", n->type);
	com64.c:549: 		default:	diag(n, "mixed vlong/double %O not implemented", n->op);
	com64.c:636: 		diag(Z, "bad type in castftox %s", tnames[et]);
	dcl.c:17: 		diag(n, "unknown declarator: %O", n->op);
	dcl.c:31: 				diag(n, "array size must be a positive constant");
	dcl.c:57: 			diag(n, "field width must be non-negative constant");
	dcl.c:64: 				diag(n, "zero width named field");
	dcl.c:69: 			diag(n, "field type must be int-like");
	dcl.c:74: 			diag(n, "field width larger than field unit");
	dcl.c:180: 		diag(initlist, "more initializers than structure: %s",
	dcl.c:305: 		diag(Z, "unknown type in initialization: %T to: %s", t, s->name);
	dcl.c:330: 			diag(Z, "cannot initialize bitfields");
	dcl.c:351: 				diag(a, "initialize pointer to an integer: %s", s->name);
	dcl.c:367: 				diag(a, "initializer is not a constant: %s",
	dcl.c:379: 				diag(a, "initialization of incompatible pointers: %s\n%T and %T",
	dcl.c:402: 			diag(a, "initializer is not a constant: %s", s->name);
	dcl.c:423: 					diag(a, "string initialization larger than array");
	dcl.c:453: 					diag(r, "initializer subscript must be constant");
	dcl.c:459: 						diag(a, "initialization index out of range: %ld", e);
	dcl.c:490: 			diag(Z, "incomplete structure: %s", s->name);
	dcl.c:513: 			diag(a, "structure element not found %F", a);
	dcl.c:553: 						diag(Z, "incomplete structure element: %s",
	dcl.c:556: 						diag(Z, "incomplete structure element");
	dcl.c:574: 					diag(Z, "incomplete union element: %s",
	dcl.c:577: 					diag(Z, "incomplete union element");
	dcl.c:591: 		diag(Z, "unknown type in sualign: %T", t);
	dcl.c:602: 		diag(Z, "rounding by %d", w);
	dcl.c:676: 		diag(n, "argument not a name/prototype: %O", n->op);
	dcl.c:702: 			diag(Z, "no name in argument declaration");
	dcl.c:758: 			diag(Z, "pop off dcl stack");
	dcl.c:831: 			diag(n, "mixed ansi/old function declaration: %F", n->left);
	dcl.c:883: 		diag(n, "incomplete argument prototype");
	dcl.c:889: 	diag(n, "unknown op in fnproto");
	dcl.c:1138: 		diag(Z, "tag used for more than one type: %s",
	dcl.c:1155: 				diag(Z, "label reused: %s", s->name);
	dcl.c:1232: 			diag(Z, "function cannot be %s %s", cnames[c], s->name);
	dcl.c:1244: 			diag(Z, "auto redeclaration of: %s", s->name);
	dcl.c:1277: 		diag(Z, "not a parameter: %s", s->name);
	dcl.c:1284: 		diag(Z, "parameter cannot have class: %s", s->name);
	dcl.c:1288: 		diag(Z, "incomplete structure: %s", t->tag->name);
	dcl.c:1319: 		diag(Z, "overspecified class: %s %s %s", s->name, cnames[c], cnames[s->class]);
	dcl.c:1325: 			diag(Z, "typestr must be struct/union: %s", s->name);
	dcl.c:1339: 			diag(Z, "external redeclaration of: %s", s->name);
	dcl.c:1396: 				diag(Z, "function inconsistently declared: %s", s->name);
	dcl.c:1428: 			diag(Z, "unnamed structure element must be struct/union");
	dcl.c:1430: 			diag(Z, "unnamed structure element cannot have class");
	dcl.c:1433: 			diag(Z, "structure element cannot have class: %s", s->name);
	dcl.c:1484: 			diag(n, "enum not a constant: %s", s->name);
	dcl.c:1609: 			diag(n, "automatic adjustable array: %s", s->name);
	dcl.c:1617: 		diag(Z, "oops in contig");
	funct.c:109: 		diag(n, "isfunct op missing %O\n", o);
	funct.c:207: 	diag(n, "cant rewrite typestr for op %O\n", o);
	funct.c:271: 			diag(Z, "dclfunct op missing %d\n", ftabinit[i].typ);
	funct.c:319: 	diag(Z, "dclfunct bad %T %s\n", t, s->name);
	lex.c:237: 			diag(Z, "cannot open %s - %r", outfile);
	lex.c:249: 			diag(Z, "-p option not supported on windows");
	lex.c:253: 			diag(Z, "%s does not exist", file);
	lex.c:257: 			diag(Z, "pipe failed");
	lex.c:262: 			diag(Z, "fork failed");
	lex.c:1055: 		diag(Z, "illegal rune in string");
	lex.c:1583: 				diag(Z, "ninclude too small %d", nelem(include));
	pgen.c:19: 			diag(nn, "cant find function name");
	pgen.c:77: 			diag(Z, "no return at end of function: %s", n1->sym->name);
	pgen.c:243: 			diag(Z, "label undefined: %s", n->sym->name);
	pgen.c:262: 			diag(n, "case/default outside a switch");
	pgen.c:275: 			diag(n, "case expression must be integer constant");
	pgen.c:291: 			diag(n, "switch expression must be integer");
	pgen.c:443: 			diag(n, "continue not in a loop");
	pgen.c:455: 			diag(n, "break not in a loop");
	pswt.c:31: 				diag(n, "more than one default in switch");
	pswt.c:66: 			diag(n, "duplicate cases in switch %lld", (vlong)iq[i].val);
	scon.c:576: 		diag(n, "not addo");
	sub.c:198: 	diag(Z, "illegal combination of classes %Q", b);
	sub.c:267: 	diag(Z, "illegal combination of types %Q", b);
	sub.c:304: 			diag(n, "incompatible type: \"%T\" for op \"%O\"",
	sub.c:307: 			diag(n, "incompatible types: \"%T\" and \"%T\" for op \"%O\"",
	sub.c:410: 	diag(n, "ambiguous structure element: %s", s->name);
	sub.c:468: 	diag(n, "ambiguous unnamed structure element");
	sub.c:775: 	diag(n, "pointer addition not fully declared: %T", n->type->link);
	sub.c:1162: 		diag(Z, "bad in relindex: %O", o);
	sub.c:1203: 	diag(Z, "bad in bitno");
	sub.c:1222: diag(Node *n, char *fmt, ...)
	y.tab.c:792: 			diag(yypt[-0].yyv.node, "not a function");
	y.tab.c:1675: 			diag(Z, "duplicate types given: %T and %Q", yypt[-1].yyv.type, yypt[-0].yyv.lval);
	y.tab.c:1710: 			diag(Z, "illegal combination of class 4: %s", cnames[yypt[-0].yyv.tycl.c]);
	y.tab.c:1734: 			diag(Z, "redeclare tag: %s", yypt[-2].yyv.sym->name);
	y.tab.c:1763: 			diag(Z, "redeclare tag: %s", yypt[-2].yyv.sym->name);
	y.tab.c:1801: 			diag(Z, "redeclare tag: %s", yypt[-5].yyv.sym->name);
	y.tab.c:1803: 			diag(Z, "enum type ambiguous: %s", yypt[-5].yyv.sym->name);

### Getting a cleaner list of errors

	tenshi% grep 'diag\(' *.c | awk -F '"' '{print $2}' | sort | uniq | wc -l
	    114
	tenshi%
	
	tenshi% grep 'diag\(' *.c | awk -F '"' '{print $2}' | sort | uniq
	
	%s does not exist
	-p option not supported on windows
	Z in tcom
	address of a bit field
	address of a register
	ambiguous structure element: %s
	ambiguous unnamed structure element
	argument not a name/prototype: %O
	argument prototype mismatch \
	array size must be a positive constant
	auto redeclaration of: %s
	automatic adjustable array: %s
	bad in bitno
	bad in bnum
	bad in relindex: %O
	bad type in castftox %s
	break not in a loop
	cannot initialize bitfields
	cannot open %s - %r
	cant find function name
	cant rewrite typestr for op %O\n
	case expression must be integer constant
	case/default outside a switch
	constructor list too long
	constructor list too short
	constructor must be a structure
	continue not in a loop
	dclfunct bad %T %s\n
	dclfunct op missing %d\n
	divide by zero
	divide check
	duplicate cases in switch %lld
	duplicate types given: %T and %Q
	enum not a constant: %s
	enum type ambiguous: %s
	external redeclaration of: %s
	field type must be int-like
	field width larger than field unit
	field width must be non-negative constant
	fork failed
	function args not checked: %F
	function cannot be %s %s
	function inconsistently declared: %s
	function not declared: %F
	illegal combination of class 4: %s
	illegal combination of classes %Q
	illegal combination of types %Q
	illegal rune in string
	inc/dec of a void pointer
	incompatible type: \
	incompatible types: \
	incomplete argument prototype
	incomplete structure element
	incomplete structure element: %s
	incomplete structure: %s
	incomplete union element
	incomplete union element: %s
	initialization index out of range: %ld
	initialization of incompatible pointers: %s\n%T and %T
	initialize pointer to an integer: %s
	initializer is not a constant: %s
	initializer subscript must be constant
	isfunct op missing %O\n
	label reused: %s
	label undefined: %s
	mixed ansi/old function declaration: %F
	mixed vlong/double %O not implemented
	modulo by zero
	more initializers than structure: %s
	more than one default in switch
	name not declared: %F
	ninclude too small %d
	no name in argument declaration
	no return at end of function: %s
	not a function
	not a member of struct/union: %F
	not a parameter: %s
	not addo
	not an l-value
	not enough function arguments: %F
	oops in contig
	overspecified class: %s %s %s
	parameter cannot have class: %s
	pipe failed
	pointer addition not fully declared: %T
	pop off dcl stack
	redeclare tag: %s
	rounding by %d
	signof bitfield
	signof undefined type
	sizeof bitfield
	sizeof function
	sizeof undefined type
	string initialization larger than array
	structure element cannot have class: %s
	structure element not found %F
	structure not fully declared
	structure not fully declared %s
	switch expression must be integer
	tag used for more than one type: %s
	too many function arguments: %F
	typestr must be struct/union: %s
	unknown %T->vlong cast
	unknown declarator: %O
	unknown op in fnproto
	unknown op in type complex: %O
	unknown type in initialization: %T to: %s
	unknown type in sualign: %T
	unknown vlong %O
	unknown vlong->%T cast
	unnamed structure element cannot have class
	unnamed structure element must be struct/union
	zero width named field
	tenshi% 


### Finding function definitions lazily
	
	tenshi% src -s diag 2c
	# /sys/src/cmd/cc/sub.c:1222 will be plumbed
	tenshi%


SRC=../trunk/
objects = Ted.o Parser.o SyntaxChecker.o LexicalAnalyzer.o \
		DiagramCreator.o DiagramHolder.o Diagram.o DiagramLoader.o \
		Rules.o Prover.o Contour.o Zone.o ProofWriter.o \
		SetMaker.o \
		CompoundNode.o \
		TreeTraversal.o InorderTraversal.o \
		ExpressionTokenizer.o \
		InfixToPostfix.o\
		TreeBuilder.o\
		CompoundTree.o\
		CompoundRules.o
	
CC = g++ -g

ted: $(objects)
	${CC}  -o ted $(objects)
	
Contour.o: ${SRC}Contour.cpp ${SRC}Contour.h
	${CC} -c ${SRC}Contour.cpp  
 
Zone.o: ${SRC}Zone.cpp ${SRC}Zone.h
	${CC}  -c ${SRC}Zone.cpp

Diagram.o: ${SRC}Diagram.cpp ${SRC}Diagram.h ${SRC}Zone.h ${SRC}Contour.h 
	${CC}  -c ${SRC}Diagram.cpp

SetMaker.o: ${SRC}SetMaker.cpp ${SRC}SetMaker.h
	${CC}  -c ${SRC}SetMaker.cpp

Rules.o:  ${SRC}Rules.cpp ${SRC}Rules.h ${SRC}Contour.h ${SRC}Zone.h 
	${CC}  -c   ${SRC}Rules.cpp

Parser.o: ${SRC}Parser.cpp ${SRC}Parser.h ${SRC}Zone.h ${SRC}Contour.h
	${CC} -c ${SRC}Parser.cpp

SyntaxChecker.o: ${SRC}SyntaxChecker.cpp ${SRC}SyntaxChecker.h ${SRC}Zone.h 
	${CC} -c ${SRC}SyntaxChecker.cpp

LexicalAnalyzer.o: ${SRC}LexicalAnalyzer.cpp ${SRC}LexicalAnalyzer.h
	${CC} -c ${SRC}LexicalAnalyzer.cpp

DiagramHolder.o: ${SRC}DiagramHolder.cpp ${SRC}DiagramHolder.h ${SRC}Diagram.h  
	${CC} -c ${SRC}DiagramHolder.cpp

DiagramCreator.o: ${SRC}DiagramCreator.cpp ${SRC}DiagramCreator.h ${SRC}Diagram.h ${SRC}Zone.h
	${CC} -c ${SRC}DiagramCreator.cpp


DiagramLoader.o: ${SRC}DiagramLoader.cpp ${SRC}DiagramLoader.h
	${CC} -c ${SRC}DiagramLoader.cpp

Prover.o:  ${SRC}Prover.cpp ${SRC}Prover.h ${SRC}Diagram.h ${SRC}Rules.h ${SRC}SetMaker.h
	${CC}  -c ${SRC}Prover.cpp

ProofWriter.o:  ${SRC}ProofWriter.cpp ${SRC}ProofWriter.h ${SRC}Diagram.h ${SRC}Zone.h ${SRC}DiagramHolder.h 
	${CC}  -c ${SRC}ProofWriter.cpp
	
CompoundNode.o: ${SRC}CompoundNode.cpp ${SRC}CompoundNode.h ${SRC}Diagram.h
	${CC} -c ${SRC}CompoundNode.cpp 

TreeTraversal.o: ${SRC}TreeTraversal.cpp ${SRC}TreeTraversal.h ${SRC}CompoundNode.h ${SRC}Diagram.h
	${CC} -c ${SRC}TreeTraversal.cpp

InorderTraversal.o: ${SRC}InorderTraversal.cpp ${SRC}InorderTraversal.h ${SRC}TreeTraversal.h ${SRC}CompoundNode.h ${SRC}Diagram.h
	${CC} -c ${SRC}InorderTraversal.cpp

ExpressionTokenizer.o: ${SRC}ExpressionTokenizer.cpp ${SRC}ExpressionTokenizer.h
	${CC} -c ${SRC}ExpressionTokenizer.cpp

InfixToPostfix.o: ${SRC}InfixToPostfix.cpp ${SRC}InfixToPostfix.h
	${CC} -c ${SRC}InfixToPostfix.cpp

CompoundTree.o: ${SRC}CompoundTree.cpp ${SRC}CompoundTree.h
	${CC} -c ${SRC}CompoundTree.cpp

TreeBuilder.o: ${SRC}TreeBuilder.cpp ${SRC}TreeBuilder.h
	${CC} -c ${SRC}TreeBuilder.cpp

CompoundRules.o: ${SRC}CompoundRules.cpp ${SRC}CompoundRules.h
	${CC} -c ${SRC}CompoundRules.cpp

Ted.o: ${SRC}Ted.cpp ${SRC}Prover.h ${SRC}SyntaxChecker.h ${SRC}LexicalAnalyzer.h \
	${SRC}Parser.h ${SRC}Diagram.h ${SRC}Rules.h \
	${SRC}DiagramCreator.h ${SRC}DiagramHolder.h \
	${SRC}Zone.h ${SRC}Contour.h ${SRC}SetMaker.h
	${CC}  -c ${SRC}Ted.cpp

clean :
	rm ted $(objects)



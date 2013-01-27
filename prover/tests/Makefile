CPPUNIT_PATH=/usr/include/cppunit
BUILD=../build/
TRUNK=../trunk/
objects = UnitTestRunner.o CompoundNodeTest.o InorderTraversalTest.o ExpressionTokenizerTest.o \
	InfixPostfixTest.o\
	TreeBuilderTest.o\
	CompoundRulesTest.o\
	${BUILD}CompoundNode.o ${BUILD}Diagram.o ${BUILD}Zone.o ${BUILD}Contour.o ${BUILD}InorderTraversal.o ${BUILD}ExpressionTokenizer.o \
	${BUILD}InfixToPostfix.o\
	${BUILD}TreeBuilder.o\
	${BUILD}CompoundTree.o ${BUILD}DiagramLoader.o \
	${BUILD}Parser.o ${BUILD}SyntaxChecker.o ${BUILD}LexicalAnalyzer.o \
	${BUILD}DiagramCreator.o \
	${BUILD}CompoundRules.o \
	

CC=g++ -g

tests: $(objects)
	${CC} -o tests $(objects) -L../build -lstdc++ -lcppunit -ldl

CompoundNodeTest.o: CompoundNodeTest.cpp CompoundNodeTest.h ${TRUNK}CompoundNode.h
	${CC} -c CompoundNodeTest.cpp -I${CPPUNIT_PATH}

InorderTraversalTest.o: InorderTraversalTest.cpp InorderTraversalTest.h
	${CC} -c InorderTraversalTest.cpp -I${CPPUNIT_PATH}

CompoundRulesTest.o: CompoundRulesTest.cpp CompoundRulesTest.h
	${CC} -c CompoundRulesTest.cpp -I${CPPUNIT_PATH}

ExpressionTokenizerTest.o: ExpressionTokenizerTest.cpp ExpressionTokenizerTest.h
	${CC} -c ExpressionTokenizerTest.cpp -I${CPPUNIT_PATH}

InfixPostfixTest.o: InfixPostfixTest.cpp InfixPostfixTest.h
	${CC} -c InfixPostfixTest.cpp -I${CPPUNIT_PATH}

TreeBuilderTest.o: TreeBuilderTest.cpp TreeBuilderTest.h ${TRUNK}CompoundNode.h ${TRUNK}CompoundTree.h
	${CC} -c TreeBuilderTest.cpp -I${CPPUNIT_PATH}

UnitTestRunner.o: UnitTestRunner.cpp
	${CC} -c UnitTestRunner.cpp -I${CPPUNIT_PATH}

clean:
	rm -f *.o tests 

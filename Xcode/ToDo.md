DONE - Add getPartSpec function to IPart (etc)
DONE - Use getPartSpec function to find out the number of staves in the part and set the musicxml staff->properties->staves element.

Features
Add beaming support in lyre and lmx
Add tuplet support in lyre and lmx

Cleanup
eliminate these functions from IDuration -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
eliminate these functions from IDurDot -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
Add tests for getDurBase() for both IDuration and IDurDot

add to Xcode IMeasureStrategy.h
add to Xcode IMeasureStrategyFactory.h
add to Xcode IMeasureStrategyFactory.cpp
add to Xcode MeasureStrategy.h
add to Xcode MeasureStrategy.cpp
add to Xcode MeasureStrategyFactory.h
add to Xcode MeasureStrategyFactory.cpp
implement MeasureStrategy.h
implement MeasureStrategy.cpp
implement IMeasureStrategy.h
implement MeasureStrategyFactory.h
implement MeasureStrategyFactory.cpp
implement IMeasureStrategyFactory.h
implement IMeasureStrategyFactory.cpp

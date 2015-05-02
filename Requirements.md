
### Basic
All Objects which represent items present in music notation will have an isHidden bool.
INotatable
INote
IMeasure
IClef
IAccidental(?)
ITimeSignature

All object will also implement
IWhatever::make() which returns a shared pointer.
IWhatever::umake() which returns a unique pointer.
someIWhatever->clone() which deep copies and returns a shared pointer.
someIWhatever->uclone() which deep copies and returns a unique pointer.

### Part
A Part will contain a set of Measures.
It should be possible to add a Measure (or Measures) to the end of a part or to insert a Measure or Measures at a given location in a Part. 

### Measures
A Measure can have 1 or many MeasureLayers

A Measure has a Time Signature which determines the total duration of Notes, Explicit Rests and Implicit Rests that can be contained within the MeasureLayer.

A Measure has a display Time Signature which can be different than the actual Time Signature.

A Measure has a list of Clef changes which represent mid-measure Clef changes.  These Clef changes are attached to notes and staves via pointers (or iterators?) to the first affected note and the correct Staff.

#### MeasureLayer

A MeasureLayer can only hold the correct total duration of Notes.  Additional Notes cannot be added to the MeasureLayer once the total duration of the MeasureLayer has been reached.

A MeasureLayer will automatically fill-out the remainder of its time with "implicit" rests.  These rests will be overwritten/adjusted automatically if additional Notes or explicit rests are added to the MeasureLayer.


A MeasureLayer has can have zero or many Staves.  For example a MeasureLayer in a piano Part might have two Staves.  A Note is connected to a Staff by way of a pointer.

A Staff (within each measure) has a beginning Clef.

### Time Signature
A TimeSignature has Duration named "BeatType" which represents the bottom number in a Time Signature.

A TimeSignature will have an Int representing the number of beats (the top number in a Time Signature).

### Piece
A Piece can have one or many Movements.
A Piece has a Title.
A Piece has a Composer.
A Piece has a CompletionDate.
A Piece has a CopyrightDate.
A Piece has a CopyrightString.
A Piece has a Lyricist.
A Piece has zero or many Name Value string pairs for OtherCredits.
A Piece will return an IMovementIterator.

### Movement
A Movement has a Title.
A Movement has one or many ScoreGroups.

### ScoreGroup
A ScoreGroup has one or many Parts.

### Note
A Note has a Duration.
A Note has a Pitch.
A Note can have zero or many Articulations.

### Rest
A Rest is implicit if it has been added to the Measure automatically by the Measure's algorithm.
A Rest is explicit if it has been added by the user.

### Iterators
IMovementIterator
IScorePartIterator
IPartIterator
IMeasureIterator

### Memory and Pointers
All non-trivial or extensible classes will have a pure virtual base class.

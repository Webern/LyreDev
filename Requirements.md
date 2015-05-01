
### Basic
All Objects which represent items present in music notation will have an isHidden bool.

### Measures
A Measure can only hold the correct total duration of Notes.  Additional Notes cannot be added to the Measure once the total duration of the Measure has been reached.

A Measure will automatically fill-out the remainder of its time with "implicit" rests.  These rests will be overwritten/adjusted automatically if additional Notes or explicit rests are added to the Measure.

A Measure has a Time Signature which determines the total duration of Notes, Explicit Rests and Implicit Rests that can be contained within the Measure.

A Measure also has a display Time Signature which can be different than the actual Time Signature.

Every Measure has a beginning Clef.

A Measure has a list of Clefs which represent mid-measure Clef changes.  These Clef changes are attached to notes via pointers to the first affected note.

### Time Signature
A TimeSignature has Duration named "BeatType" which represents the bottom number in a Time Signature.

A TimeSignature will have an Int representing the number of beats (the top number in a Time Signature).

### Iterators

### Memory and Pointers
All non-trivial or extensible classes will have a pure virtual base class.

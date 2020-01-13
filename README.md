# sa-movement-rnd

This project aims to understand how the unique movement of SADX and SA2 work under the hood so that it can be re-created in other contexts.

## Project Structure

### sa-movement-rnd
This is a static library whose purpose is housing shared code. There is currently none.

### sadx-movement-rnd
SADX-specific research and development. A brief overview:

##### structs.h
Intermediate structures based on the disassembly directly. They differ from the `sadx-mod-loader` distribution. The intent is to finish the research using these intermediate structures, and once verified/completed, merge the changes up-stream.

##### HandleFloorVelocity.h
A mostly cleaned and labelled version of the decompiled function of the same name from the disassembly. Utilizes the structures in `structs.h` heavily. Likewise, the intent is to merge any changes to function labels or signatures up-stream once verified/completed.

# Controls and Software for Soft Robotic Exoglove 

![Screenshot of startup phase](images/startup_sequence.jpg)



## Docs
 
Install Doxygen, then generate the docs from the code comments:
 
```bash
sudo apt install doxygen graphviz   # or: brew install doxygen graphviz
doxygen -g Doxyfile                 # first time only
doxygen Doxyfile
```
 
Open `docs/html/index.html`.
 
In `Doxyfile`, set `INPUT = main README.md`, `FILE_PATTERNS = *.c *.h *.md`, `OUTPUT_DIRECTORY = docs` and `GENERATE_LATEX = NO`.
 
Document functions in the `.h` files like this:
 
```c
/**
 * @brief Run the startup sequence.
 * @return STARTUP_OK, or an ABORT_* code.
 */
```

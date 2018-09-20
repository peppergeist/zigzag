# zigzag
`zigzag` is a useless command-line program which outputs its input, except all zigzaggedy.

## Installation
Installation is straightforward. To build, run `make`. To install to path, run `make install`. To uninstall, run `make uninstall`.

## Usage
To zigzag text, run `zigzag [input]`. This will zigzag the text up and down five rows by default. You can also pipe input to zigzag, for example: `fortune | zigzag`. Note that this program makes nearly any output completely illegible.

Additionally, you may provide the following options to `zigzag` in order to give yourself some more control over the output:
* `zigzag [-h | --height] [value] input`: This will make zigzag set the height to `value`.
* `zigzag [-r | --reverse] input`: This will make the text zigzag starting from the bottom rather than the top.
* `zigzag [-v | --version] input`: This will print the version information of `zigzag` prior to displaying any output.

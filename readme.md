# HexCat(hc) - Hex Viewer & Dumper

`HexCat(hc)` is a lightweight and fast command-line tool to display binary files in hexadecimal format

---

## Features

- Display binary files in **hexadecimal**.
- Optional **ASCII column** (canonical mode).
- **Verbose mode** for debugging.
- Skip bytes from start of file.
- Limit displayed bytes.
- Group bytes for better readability.
- Output hex dump to a file.
- Optional **colorful display**.
---
## Installation

Compile the program using `make`:

```bash
git clone https://github.com/selimozturk13/HexCat.git
cd HexCat
make && make install
```
---
## Usage
`hc [options] <file>`

| Short | Long             | Description                               |
|-------|------------------|--------------------------------------------|
| -h    | --help           | Show this help message and exit            |
| -V    | --version        | Show version information                   |
| -v    | --verbose        | Enable verbose mode                        |
| -r    | --row-size <num> | Number of bytes per row (default: 16)      |
| -C    | --dis-canonical  | Disable canonical (ASCII) mode             |
| -c    | --dis-colourful  | Disable coloring                           |
| -s    | --skip <num>     | Skip bytes from start of file              |
| -l    | --length <num>   | Limit display to specified number of bytes |
|       | --only-hex       | Display only hex, no ASCII column          |
| -g    | --group <num>    | Group bytes                                |
| -o    | --output <file>  | Write hex dump to a file                   |

---

## Examples

- Display file with default settings:

    `hc test.bin`

- Display only hex (no ASCII):

    `hc test.bin --only-hex`


- Skip first 32 bytes and show 64 bytes:

    `hc test.bin -s 32 -l 64`


- Group bytes by 4 and write output to a file:

    `hc test.bin -g 4 -o dump.txt`


- Enable verbose mode:

    `hc test.bin -v`

---

## Notes

- It works on **Unix, Linux, macOS etc.**
- Hex colors: blue = 0x00, red = 0xFF, yellow = printable ASCII, gray = non-printable ASCII.
- Binary files are read in binary mode, so it supports any file type.

---

## License

This project is licensed under the GNU General Public License v3.0 or later.  
See the [LICENSE](LICENSE) file for the full text.


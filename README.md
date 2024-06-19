**Project Description: The Image Processing Software (TIPS) Version 0.1**

**Introduction:**
TIPS, The Image Processing Software, is a robust command-line tool developed in the C programming language. It provides a suite of image processing techniques compatible with various file formats, including PPM, PGM, and PBM. Designed for efficiency and versatility, TIPS facilitates the transformation of RGB images into grayscale, generates negative images, and allows the extraction of individual color channels.

**Features:**
- **Supported File Formats:** PPM, PGM, PBM
- **Image Processing Operations:**
  - **RGB to Grayscale Conversion (-G)**
  - **Red Channel Extraction (-r)**
  - **Green Channel Extraction (-g)**
  - **Blue Channel Extraction (-b)**
  - **RGB to Negative Image (-N)**
  - **Grayscale to Negative Image (-N)**

**System Requirements:**
- **Bash Version:** 5.1.16(1) or higher
- **Operating System:** Ubuntu 22.04.3 LTS x86_64 (tested environment)

**Installation:**
1. Unzip the TIPS zip file.
2. Navigate to the directory containing the source code.
3. Provide executable permissions to the compiled binary using the command:
   ```bash
   chmod +x TIPS
   ```

**Usage:**
Execute TIPS with the following command format:
```bash
./TIPS input_file [options]
```
- **input_file:** Path to the input image file (supported formats: PPM, PGM, PBM)
- **options:**
  - `-G`: Convert RGB image to grayscale
  - `-r`: Extract red channel as grayscale
  - `-g`: Extract green channel as grayscale
  - `-b`: Extract blue channel as grayscale
  - `-N`: Generate negative image

**Example:**
To generate a green grayscale image from an input file named "blackbuck.ppm":
```bash
./TIPS blackbuck.ppm -g
```

**Notes:**
- Ensure the input file exists and is in one of the supported formats (PPM, PGM, PBM).
- TIPS outputs the processed image to the standard output. Redirect the output to a file using standard shell redirection operators if needed.

**Acknowledgments:**
TIPS was developed by Pankaj Mondal. For further assistance or inquiries, please contact Pankaj at pankajm.1093@gmail.com.

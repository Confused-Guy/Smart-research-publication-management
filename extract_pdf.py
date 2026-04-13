#!/usr/bin/env python3
"""
Extract plain text from PDF files using PyMuPDF (fitz)
Handles various PDF types including image-based PDFs
Usage: python extract_pdf.py <path_to_pdf>
"""
import sys
import os

# Ensure UTF-8 output encoding on Windows
if sys.platform == "win32":
    import io
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    sys.stderr = io.TextIOWrapper(sys.stderr.buffer, encoding='utf-8')

try:
    import fitz  # PyMuPDF
except ImportError:
    print("ERROR: PyMuPDF not installed. Install with: pip install PyMuPDF")
    sys.exit(1)

def extract_text_from_pdf(pdf_path):
    """Extract all text from a PDF file using multiple methods."""
    try:
        # Debug: Verify file exists and is accessible
        if not os.path.exists(pdf_path):
            print(f"ERROR: File does not exist: {pdf_path}", file=sys.stderr)
            sys.exit(1)
        
        if not os.access(pdf_path, os.R_OK):
            print(f"ERROR: File not readable (permission denied): {pdf_path}", file=sys.stderr)
            sys.exit(1)
        
        file_size = os.path.getsize(pdf_path)
        if file_size == 0:
            print("ERROR: PDF file is empty (0 bytes)", file=sys.stderr)
            sys.exit(1)
        
        # Try to open the PDF
        try:
            document = fitz.open(pdf_path)
        except Exception as open_error:
            error_str = str(open_error).lower()
            if "encrypted" in error_str:
                print("ERROR: PDF is encrypted or password-protected", file=sys.stderr)
            elif "corrupt" in error_str or "invalid" in error_str:
                print(f"ERROR: PDF is corrupted or invalid format: {str(open_error)}", file=sys.stderr)
            elif "not a pdf" in error_str:
                print("ERROR: File is not a valid PDF", file=sys.stderr)
            else:
                print(f"ERROR: Could not open PDF: {str(open_error)}", file=sys.stderr)
            sys.exit(1)
        
        page_count = len(document)
        
        # Handle empty PDFs
        if page_count == 0:
            print("ERROR: PDF has no pages", file=sys.stderr)
            sys.exit(1)
        
        text = []
        
        # Extract text from each page
        for page_num in range(page_count):
            try:
                page = document[page_num]
                # Use simple get_text() - proven to work with PyMuPDF
                page_text = page.get_text()
                
                # Add page text if extracted
                if page_text and len(page_text.strip()) > 0:
                    text.append(page_text)
                    
            except Exception as page_error:
                # Skip pages that can't be read
                continue
        
        document.close()
        
        # Check if we extracted any text
        if not text:
            print("ERROR: No extractable text found in PDF. PDF may be image-only, corrupted, or use unsupported encoding.", file=sys.stderr)
            sys.exit(1)
        
        result = "\n".join(text)
        
        # Verify we got some reasonable output
        if len(result.strip()) == 0:
            print("ERROR: Extracted text is empty after processing", file=sys.stderr)
            sys.exit(1)
        
        return result
        
    except Exception as e:
        print(f"ERROR: Unexpected error during extraction: {str(e)}", file=sys.stderr)
        import traceback
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("ERROR: No file path provided", file=sys.stderr)
        sys.exit(1)
    
    pdf_path = sys.argv[1]
    
    if not os.path.exists(pdf_path):
        print(f"ERROR: File not found: {pdf_path}", file=sys.stderr)
        sys.exit(1)
    
    text = extract_text_from_pdf(pdf_path)
    print(text)

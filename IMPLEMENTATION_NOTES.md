# File Preview and AI Manuscript Analysis Implementation

## Summary
Successfully implemented file preview functionality and AI-powered manuscript acceptance checking for the Smart Research Publication Management system.

## Features Implemented

### 1. File Preview Dialog (`filepreviewdialog.h` / `filepreviewdialog.cpp`)
- **Supported Formats**: TXT, DOCX, PDF
- **Features**:
  - Opens files in a new dialog window with embedded viewer
  - Displays file name, size/type information, and content
  - Includes refresh button to reload file content
  - Read-only text display with word wrapping
  - Handles file extraction for DOCX (strips XML tags and extracts plain text)
  - PDF support shows a message indicating specialized viewing needed

### 2. Ollama Integration (`ollamaintegration.h` / `ollamaintegration.cpp`)
- **Model**: llama3.1:8b (configurable)
- **Features**:
  - Communicates with Ollama via HTTP API (localhost:11434 by default)
  - Checks Ollama availability before processing
  - Extracts text from manuscripts and sends to AI for analysis
  - Receives acceptance probability percentage (0-100)
  - Handles timeouts gracefully (60-second limit for AI analysis)
  - Includes error handling and user feedback

### 3. UI Integration (`mainwindow.ui` / `mainwindow.h` / `mainwindow.cpp`)
- **New Buttons**:
  - "Preview" button on Submission page (near Edit/Delete buttons)
  - "Ai checker" button (existing, now connected to AI functionality)
  
- **Button Behavior**:
  1. Select a submission/review from the table
  2. Manuscript path is automatically captured
  3. Click "Preview" to open file viewer dialog
  4. Click "Ai checker" to analyze manuscript with AI

### 4. Project Configuration (`Smart.pro`)
- Added new source files: `filepreviewdialog.cpp`, `ollamaintegration.cpp`
- Added new header files: `filepreviewdialog.h`, `ollamaintegration.h`
- Project now includes Qt Network module for HTTP communication

## How to Use

### Import the following module if not already present:
- Qt Network (used for HTTP requests to Ollama)

### Preview a Manuscript:
1. Navigate to submission page
2. Select a submission from the table (it will highlight the manuscript path)
3. Click the "Preview" button
4. File content will display in a new dialog window
5. Click "Refresh" to reload, or "Close" to exit

### Check Manuscript Acceptance Probability:
1. Ensure Ollama is running with llama3.1:8b model loaded
   - Start ollama: `ollama serve`
   - Pull model: `ollama pull llama3.1:8b`
2. Select a submission from the table
3. Click the "Ai checker" button
4. The system will:
   - Verify Ollama is available
   - Extract text from manuscript
   - Send to AI for analysis
   - Display acceptance probability as a percentage
5. Result appears in a dialog showing percentag

e and explanation

## Technical Details

### File Extraction Process:
- **TXT files**: Read directly with QFile
- **DOCX files**: Extract from ZIP archive → parse word/document.xml → strip XML tags
- **PDF files**: Display message (requires external libraries for full support)

### AI Analysis Process:
1. Extracts manuscript text
2. Creates prompt asking for acceptance probability (0-100)
3. Sends HTTP POST request to Ollama API
4. Parses response and extracts numeric percentage
5. Validates percentage is in range (0-100)
6. Returns result to user

### Error Handling:
- File not found checks
- Ollama connection verification
- Timeout handling (60 seconds for AI)
- Invalid response parsing with number extraction fallback
- User-friendly error messages

## Configuration Options

### Change Ollama Server URL:
In mainwindow.cpp constructor, modify:
```cpp
ollamaIntegration = new OllamaIntegration(this);
// To set custom URL:
// ollamaIntegration->setOllamaUrl("http://your-server:11434");
```

### Change AI Model:
In mainwindow.cpp, in `on_aiChecker_clicked()` method, change parameter:
```cpp
int percentage = ollamaIntegration->checkManuscriptAcceptance(manuscriptText, "your-model-name");
```

## Requirements
- Qt 6.7.3 (or compatible version)
- Ollama installed and running (for AI check functionality)
- llama3.1:8b model downloaded in Ollama
- Network connectivity to localhost:11434

## Files Modified/Created
- **Created**: filepreviewdialog.h, filepreviewdialog.cpp
- **Created**: ollamaintegration.h, ollamaintegration.cpp
- **Modified**: mainwindow.h (added includes, slots, member variables)
- **Modified**: mainwindow.cpp (added initialization, implementations, button connections)
- **Modified**: mainwindow.ui (added Preview button)
- **Modified**: Smart.pro (added source and header files)

## Notes
- The preview and AI checker features work with the currently selected manuscript
- The `selectedManuscriptPath` is updated whenever a submission table row is selected
- Both features provide detailed error messages for troubleshooting
- AI analysis may take 30-60 seconds depending on model and system performance

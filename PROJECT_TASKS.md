# Smart Research Publication Management - Project Tasks

## Submission Module - Tasks Completed

### AA4.1: CRUD Validation (Complete ✅)
**Responsibility:** Submissions Module

#### Implemented Features:
- [x] **Create (Add)**
  - Input validation for all fields
  - Title validation (non-empty, 3-255 chars)
  - Topic validation (non-empty, 2-255 chars)  
  - Status validation (must be one of allowed statuses)
  - Author ID validation (must exist in database)
  - File upload support for citations and manuscripts
  - Error messages for validation failures

- [x] **Read (Display)**
  - Load all submissions from database
  - Display submissions in table format
  - Show ID, Title, Status, Topic, Author ID, Created Date
  - Color-coded status indicators
  - Search functionality by title

- [x] **Update (Edit)**
  - Edit submission details
  - Update status with validation
  - Modify citations and manuscripts
  - Author ID change validation
  - Automatic date tracking

- [x] **Delete**
  - Delete submission with confirmation
  - Referential integrity maintained
  - Success feedback to user

#### Validation Methods Implemented:
- `validateTitle(QString)` - Title format and length validation
- `validateStatus(QString)` - Status enum validation
- `validateTopic(QString)` - Topic format and length validation
- `validateAuthorID(int)` - Database existence check for authors
- `isValidStatus(QString)` - Status validity check

---

### Advanced Feature: Review Response Tracker (Complete ✅)
**Responsibility:** Submissions Module  
**Feature Category:** Resubmission Workflow Enforcement

#### Core Functionality:
- [x] **Review Issue Tracking**
  - Link reviews to submissions
  - Track review status (Pending, Resolved)
  - Store review comments and feedback
  - Maintain reviewer information

- [x] **Resubmission Blocking**
  - Block resubmission when status = "Revision Required"
  - Block if unresolved review issues exist
  - Warn user about pending issues
  - Allow override with confirmation (optional)

- [x] **Issue Resolution Workflow**
  - Mark individual reviews as resolved
  - Add resolution comments
  - Track resolution date
  - Display resolution status in UI

#### Backend Implementation (Review Class):
- `getBySubmissionId(int)` - Fetch all reviews for a submission
- `markAsResolved(QString)` - Mark review as resolved
- Display review status with color coding

#### Backend Implementation (Submission Class):
- `getUnresolvedReviewIssues()` - List unresolved issue IDs
- `canResubmit()` - Check if submission can be resubmitted
- Review status validation in status change logic

#### UI Implementation:
- [x] **Review Tracker Dialog**
  - Display all reviews in card format
  - Show reviewer name, date, comment
  - Display current resolution status
  - Color-coded status indicators (Green=Resolved, Red=Pending)

- [x] **"View Reviews" Button**
  - Added to submission edit dialog
  - Opens review tracker for that submission
  - Only appears for existing submissions

- [x] **Resubmission Validation**
  - Check unresolved issues before status change
  - Display warning dialog with issue list
  - Allow user to proceed or cancel

---

## Database Schema Extensions

### Review Status Enhancement
- Added support for "Resolved" status in reviews
- Enhanced comment field to track resolution notes
- Maintains referential integrity with submissions

### Submission-Review Linking
- Foreign key: SUBMISSION_ID in REVIEW table
- Enables efficient querying of submission reviews
- Supports cascade updates and deletes

---

## Testing Checklist

### CRUD Validation Testing
- [ ] Create submission with invalid title (empty/too short)
- [ ] Create submission with invalid topic
- [ ] Create submission with non-existent author ID
- [ ] Update submission with valid data
- [ ] Delete submission and verify removal
- [ ] Search submissions by title

### Review Response Tracker Testing
- [ ] View reviews for a submission with multiple reviews
- [ ] Attempt resubmission with unresolved issues (should warn)
- [ ] Mark review as resolved and retry submission
- [ ] Verify color-coded status indicators
- [ ] Test resolution comment capture

---

## Files Modified

### Core Implementation Files
- `submission.h` - Added validation and review tracking methods
- `submission.cpp` - Implemented validation logic and review querying
- `review.h` - Added methods for review management
- `review.cpp` - Implemented review tracking methods
- `mainwindow.h` - Added method declarations for UI
- `mainwindow.cpp` - Implemented UI dialogs and validation logic

### Commits
- **Commit:** `9c7b4d8` - feat(submission): implement CRUD validation and review response tracker
  - 6 files changed, 425 insertions

---

## Notes for Future Development

### Potential Enhancements
1. Email notifications when reviews are assigned
2. Bulk marking of reviews as resolved
3. Review analytics and statistics
4. Custom review templates
5. Integration with AI for suggested responses to reviews

### Known Limitations
- Manual resolution of reviews (could be enhanced with AI)
- No automatic deadline tracking for revisions
- No version control for manuscript revisions

---

## Project Management (AA3.1)

### Submission Module Status
- **Module Owner:** Submissions
- **Status:** In Development
- **Last Updated:** 2025-01-[Current Date]
- **Completion:** 60% (CRUD + Advanced Feature complete, Documentation + Testing pending)

### Version Control
- **Repository:** GitHub
- **Branch:** main
- **Latest:** Production-ready for testing


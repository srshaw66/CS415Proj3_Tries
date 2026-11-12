# CS415 Project 3 — Requirements and Code Audit

## Purpose

This document converts the Project 3 report template into an implementation and verification checklist. An AI coding assistant should use it to compare the actual codebase against expected functionality, identify incomplete features, and determine what remains necessary to produce the final report.

**Source:** `P3_reportTemplate.docx`

**Important:** This document is derived from the report template, not the complete project assignment. Additional project instructions take precedence. Do not assume requirements not stated in available sources.

## 1. Required Data Structures

The project compares two implementations:
- Standard Trie
- BST-based Trie

### Requirements
- [ ] Standard Trie implementation exists.
- [ ] BST-based Trie implementation exists.
- [ ] Both can be constructed from input files.
- [ ] Both support prefix searching.
- [ ] Both support autocomplete.
- [ ] Both support searching all input strings.
- [ ] Both produce equivalent autocomplete results for identical inputs.
- [ ] Both track operation counts for required workloads.

**Verification:** Identify the functions responsible for each operation and verify behavior with tests, not just function names.

## 2. Trie Building — Case 1

### Required Input Files
- `test.txt`
- `test2.txt`
- `tale.txt`
- `words-alpha.txt`

### Required Measurements (for each file)
1. Number of words.
2. Standard Trie build operation count.
3. BST-based Trie build operation count.
4. Standard Trie space usage.
5. BST-based Trie space usage.

### Completion Checklist
- [ ] All four input files are supported.
- [ ] Both tries are constructed using the same input data.
- [ ] Number of words is reported.
- [ ] Standard Trie build operations are counted.
- [ ] BST-based Trie build operations are counted.
- [ ] Standard Trie space usage is measured.
- [ ] BST-based Trie space usage is measured.
- [ ] Results can be recorded in the report table.

### Reflection 1
Explain why construction operation counts and memory usage differ, and whether experimental results match theoretical expectations. The code must provide measurements; do not fabricate reflections or results.

## 3. Autocomplete — Case 1

### Required Queries

**tale.txt:** `re`, `fr`, no-match, high-branching, low-branching, complete-word prefix.

**words-alpha.txt:** `abac`, `miser`, no-match, high-branching, low-branching, complete-word prefix.

The descriptive categories require choosing actual queries suitable for each dataset.

### Required Measurements (for every query)
1. Number of autocomplete results.
2. Standard Trie search operations.
3. BST-based Trie search operations.
4. Standard Trie autocomplete operations.
5. BST-based Trie autocomplete operations.

### Completion Checklist
- [ ] Both implementations accept prefix queries.
- [ ] Both return the same set of matching strings.
- [ ] Number of results is counted.
- [ ] Search operation counts are recorded separately.
- [ ] Autocomplete operation counts are recorded separately.
- [ ] All specified queries are tested.
- [ ] Four additional query categories are tested for each file.
- [ ] Outputs are available for report evidence.

### Reflection 2
Explain the effect of query length, branching factor, complete-word status, and autocomplete subtree size. Compare both implementations and whether either consistently requires fewer operations. Verify result equivalence independently of operation counts.

## 4. Search-All — Case 2

### Required Input Files
- `test.txt`
- `test2.txt`
- `tale.txt`
- `words-alpha.txt`

### Required Measurements (for each file)
1. Number of strings searched.
2. Standard Trie build operations.
3. Standard Trie search-all operations.
4. BST-based Trie build operations.
5. BST-based Trie search-all operations.

### Completion Checklist
- [ ] Case 2 search-all functionality exists.
- [ ] All four input files can be processed.
- [ ] Both tries are built for the workload.
- [ ] Every required input string is searched.
- [ ] Number of strings searched is reported.
- [ ] Build and search-all operation counts remain separate.
- [ ] Results can be recorded in the report table.

### Reflection 3
Compare search operation counts for the two implementations, considering characters searched, child comparisons, and array lookups.

### Reflection 4
Compare Trie construction against searching all input strings, identifying which workload requires more operations and why. Verify that build and search measurements are independently available.

## 5. Report Evidence

- [ ] Trie building output is available.
- [ ] Autocomplete output is available.
- [ ] Search-all output is available.
- [ ] Output identifies the relevant input file or query.
- [ ] Operation counts are clearly identifiable.
- [ ] Results can be copied or captured as screenshots.
- [ ] All report tables can be populated from actual program output.

Reflections and screenshots are documentation deliverables, not necessarily missing program functionality.

## 6. AI Code Audit Instructions

When asked to assess project completeness:
1. Read this document and the original assignment instructions.
2. Inspect the actual project files.
3. Identify the entry point, data structures, algorithms, operation counters, and output functions.
4. Map each requirement to its relevant file and function.
5. Distinguish implemented functionality from verified functionality.
6. Run existing tests when possible.
7. Test missing scenarios when appropriate.
8. Report discrepancies between implementations.
9. Identify missing measurements needed for the report.
10. Do not modify code unless explicitly instructed.

### Status Definitions
- **PASS:** Implemented and verified through inspection and/or execution.
- **PARTIAL:** Implemented but missing required behavior.
- **FAIL:** Tested and found incorrect.
- **MISSING:** No implementation found.
- **UNVERIFIED:** Appears present but correctness has not been established.
- **BLOCKED:** Cannot verify due to unavailable inputs or dependencies.
- **REPORT ONLY:** Requires documentation or evidence rather than program functionality.

### Required Audit Output

| Requirement | Status | Code location | Evidence / issue |
|---|---|---|---|
| Standard Trie | | | |
| BST-based Trie | | | |
| Trie building | | | |
| Build operation counters | | | |
| Space measurements | | | |
| Prefix search | | | |
| Autocomplete | | | |
| Autocomplete operation counters | | | |
| Query coverage | | | |
| Search-all | | | |
| Search-all operation counters | | | |
| Required input files | | | |
| Report-ready output | | | |

Then provide:
- **A. Implementation completeness:** Counts by status.
- **B. Critical problems:** Bugs or missing functionality preventing workloads.
- **C. Remaining work:** Prioritized implementation tasks.
- **D. Report readiness:** Tables, reflections, and appendix evidence that verified output supports.
- **E. Recommended next step:** The single highest-priority task.

Do not claim completion merely because functions exist. Verify their behavior and outputs wherever possible.

## 7. Source Limitations

The report template does not independently establish:
- Precise definitions of basic operations to count.
- Precise accounting method for space usage.
- Required programming language.
- Internal representation of the BST-based Trie.
- Detailed input parsing rules.
- Required command-line interface or menu structure.

Check these against the full project instructions before enforcing implementation-specific rules. Do not invent requirements or silently substitute assumptions.

## Final Audit Goal

Determine whether the codebase can produce every measurement and output required by the Project 3 report template, whether both Trie implementations behave correctly, and exactly what remains unfinished.

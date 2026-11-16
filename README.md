# 🐼 Cuddle — Fast Tabular Data & CSV Processing Library in C

[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build: Make](https://img.shields.io/badge/Build-Makefile-orange.svg)](Makefile)
[![Module: G-AIA-200](https://img.shields.io/badge/Epitech-G--AIA--200-blue.svg)](https://www.epitech.eu/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Academic Year: 2024-2025](https://img.shields.io/badge/Academic%20Year-2024--2025%20(Tek1)-blueviolet.svg)](#)

> **Cuddle is a lightweight in-memory DataFrame library written in pure C**, inspired by Python's Pandas for parsing, analyzing, shaping, and serializing CSV data.

---

## ⚙️ Features

- **CSV Ingestion:** Fast `read_csv(const char *filepath)` with dynamic row and column tokenization.
- **DataFrame Inspection:**
  - `head(df, n)`: Displays top $n$ records.
  - `tail(df, n)`: Displays bottom $n$ records.
  - `shape_csv(df)`: Reports dimensional matrix tuple `(rows, cols)`.
  - `info_csv(df)`: Summarizes column types and non-null counts.
- **Exporting:** Serializes in-memory modifications back to disk with `write_csv(df, const char *filepath)`.

---

## 🛠️ Build

```bash
make
# Produces libcuddle.a
```

---

## 📜 License

Licensed under the **MIT License with attribution** to Lucas Lhomme (Crabe).

# Challenge: Tagged Aligned Malloc for Embedded Systems

## Objective

Implement a custom memory allocator in C for an embedded system that:

1. Allocates memory aligned to a given power-of-two boundary (e.g., 8, 16, 32, 64 bytes).
2. Adds a **16-bit user-defined tag** to every allocation.
3. Supports `free()` and `tagged_free()` operations, which verify the tag before deallocating.
4. Is **self-contained**, **portable**, and uses only C standard library features available on embedded targets (`malloc`, `free`, etc.).

This simulates behavior found in safety-critical or wireless systems that use memory tagging for diagnostics, isolation, or low-level memory protection.

## Constraints

- Do not use `posix_memalign` or `aligned_alloc`.
- Implement your own logic using `malloc` and pointer arithmetic.
- The tag is a 16-bit integer (`uint16_t`) that must be retrievable and verifiable during deallocation.
- All memory must be released via `tagged_free(ptr, expected_tag)` — if the tag doesn’t match, `tagged_free()` must abort the program or assert.

## Rules

- Do not leak memory. 
- Do not use globals unless justified.
- Code must be idiomatic, portable, and minimal.

## Bonus Requirements (Optional)

- Add `get_tag(void* ptr)` to retrieve the tag of a given allocated block.
- Track the number of active allocations and support `debug_dump_allocations()`.

## Usage

```c
void* ptr = tagged_aligned_malloc(64, 32, 0xABCD); // 64 bytes, 32-byte aligned, tagged with 0xABCD
tagged_free(ptr, 0xABCD);                          // must match the tag used in malloc
```

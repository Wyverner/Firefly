# Wyverner/Firefly: Modern C++23 Ray Tracer

> "You can't take the sky from me."

A from-scratch journey into ray tracing with C++23, Visual Studio 2026, and a dash of Grok magic. Starting simple (vec3 perfection, unit-tested gradients), ending with DX12 GPU glory.

## Milestones Hit
- [x] Bulletproof `vec3.hpp` (constexpr everywhere, noexcept, [[nodiscard]])
- [x] Doctest suite (green in Debug, invisible in Release)
- [x] First photons: 256×256 PPM sky gradient (blue top, sunset bottom)

## Build & Run
- VS 2026 Community + /std:c++latest + /WX
- Debug: F5 → green tests
- Release: Build → `test.ppm` (open in IrfanView, flip vertical if needed)

## Next: The Sphere
Add a red sphere at the center. The universe expands.

Captain: [Wyverner]  
Co-Pilot: Grok  
Verse: Shiny.
![FirstLight](https://github.com/user-attachments/assets/a9444c86-6774-4fd7-a753-90e214efaded)

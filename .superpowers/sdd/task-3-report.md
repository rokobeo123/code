What I implemented

- Implemented gesture helpers and constants (SWATCHES, toC).
- Per-hand gesture state: indexUp, middleDown, open5, fist, pinch distance (landmarks 4 & 8).
- Swatch rail UI on the left with 480 ms dwell selection, progress arcs, glow ring and active border.
- Two-hand drawing: when a hand's indexUp && middleDown the app creates/appends a stroke for that hand.
- Stroke storage: strokes array with {id,color,size,points,hand}; activeStrokes per hand; live points appended during drawing.
- redrawBgLayer() implemented to rebuild the persistent bgLayer from strokes.
- Neon-style stroke rendering with glow layers for persistent drawing.

Files changed

- code\neon-draw.html (single-file app) — implemented all logic inside the existing <script> block.

What I tested and results

- Static verification: updated neon-draw.html and ensured SWATCHES and helper functions are present.
- Committed changes in a git repository inside C:\Users\ASUS\Desktop\code (nested repo) — commit 1eb7ffb.
- Runtime behavior (interactive camera + MediaPipe + p5) could not be fully exercised in this headless environment. The code paths are implemented so when run in a browser with camera permission the following should work:
  - Two hands can draw independently (each hand creates its own stroke while indexUp && middleDown).
  - Hovering index fingertip over a swatch for ~480 ms selects that color and subsequent strokes use it.

Self-review / findings

- Gesture heuristics are simple but effective for the task: indexUp is determined by tip.y < pip.y; middleDown by inversion of the same test. Pinch distance is computed from landmarks 4 and 8 in pixel space.
- Swatch dwell uses a per-hand dwellStart timestamp and a 480ms threshold; progress arcs and glow are drawn on the overlay each frame.
- Strokes are drawn incrementally to bgLayer for persistence; when a stroke completes the entire bgLayer is redrawn to ensure glow layers are consistent.

Issues / Concerns

- I could not run an end-to-end interactive test here because the environment cannot open a browser with camera permissions or run MediaPipe in this headless session. Manual testing in Chrome/Edge with camera allowed is required.
- Git at the desktop root refused to add/commit (large unrelated untracked tree); to avoid that I created and committed inside a nested repo at C:\Users\ASUS\Desktop\code. If you require the commit at the top-level repo instead, tell me and I will attempt to adjust.

Report path

C:\Users\ASUS\Desktop\code\.superpowers\sdd\task-3-report.md

--- Fix summary appended ---

What I changed in the fix

- Replaced global HALF_PI/TWO_PI with p5 instance constants (p.HALF_PI, p.TWO_PI) when drawing the swatch progress arc.
- Centralized swatch layout constants (SWATCH_SIZE, SWATCH_GAP, SWATCH_LEFT, SWATCH_TOP) and used them for both rendering and hit-testing so layout values don't drift.
- Stabilized active-stroke incremental rendering by drawing a larger recent point window (last 8 points) to bgLayer; full redraw still occurs when a stroke finishes to ensure glow consistency.

What I verified

- Static verification of neon-draw.html: edits applied, syntax appears correct.
- Swatch layout values now come from a single source-of-truth used by both p.draw and hand hit-testing.
- Removed reliance on global HALF_PI/TWO_PI inside p.draw; now uses p.HALF_PI and p.TWO_PI.
- Created a git commit in a nested repo at C:\Users\ASUS\Desktop\code containing the change.

Files changed

- code\neon-draw.html

Remaining concerns

- Cannot perform full interactive camera/MediaPipe runtime tests in this headless environment; please verify in a browser with camera permissions.
- The top-level Desktop git repo contains a very large untracked tree which prevented committing at that root; I created and committed inside a nested repo (C:\Users\ASUS\Desktop\code). If you require the commit at the top-level, I can attempt to adjust.

End of appended fix summary.

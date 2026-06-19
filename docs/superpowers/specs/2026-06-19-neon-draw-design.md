# Neon Draw Design

## Goal
Create one standalone HTML file, `neon-draw.html`, that turns a camera feed into a neon finger-painting board using MediaPipe Hands and p5.js.

## Scope
- Single file only.
- Desktop-first layout.
- Two-hand tracking.
- Drawing, color picking, stroke moving, fist-to-shatter, and basic HUD.
- No extra libraries beyond the two requested CDN scripts and Google Fonts.

## Visual system
- Camera fills the page behind everything with `opacity: 0.55` and mirrored video.
- p5 canvas stays transparent and sits above the camera.
- Typography uses Orbitron for the HUD and Inter for secondary text.
- Primary accents are cyan `#00f5ff` and magenta `#ff00ff`, with the rest of the swatches available for drawing.
- UI uses glassmorphism for the top bar and subtle glow everywhere else.

## Core architecture
- `video`: hidden DOM video element feeding MediaPipe and mirrored display.
- `bgLayer`: persistent `p5.Graphics` buffer that stores committed strokes.
- main canvas: cleared every frame so the camera remains visible through transparent areas.
- `Spark[]`: short-lived flame particles for drawing trails.
- `Shard[]`: short-lived polygon debris for shatter bursts.
- `strokes[]`: logical stroke records with points, color, and size.
- per-hand state: current gesture, active stroke, pinch target, dwell target, and fist/open transitions.

## Drawing
- A hand draws only when index finger is extended and middle finger is curled.
- Both hands may draw at the same time, independently.
- Each live stroke is appended with mirrored canvas coordinates derived from normalized landmarks.
- Every rendered segment uses `neonLine()` to paint four stacked glow layers.
- Each new segment also spawns flame sparks that drift upward, fall under gravity, and fade out.

## Color selection
- A vertical swatch rail sits on the left edge inside a `W - 70px` active region.
- Swatches are the nine colors provided in the request.
- Hovering the index fingertip on a swatch for 480 ms selects it.
- Selection shows a progress arc, glow ring, and white active border.

## Pinch move
- Pinch is detected from thumb tip `lm[4]` and index tip `lm[8]`.
- While pinching, the nearest stroke to the pinch point can be moved.
- Moving a stroke updates its stored points and triggers `redrawBgLayer()` so the persistent layer stays in sync.

## Fist to shatter
- Open5 is detected when four fingers are extended.
- When a hand transitions from fist to open5, the app triggers shatter mode.
- The app samples roughly 40 points across each stroke, spawns shard particles, clears `strokes[]`, and clears `bgLayer`.
- Shards are 3–5 sided polygons with layered neon glow, gravity, rotation, and fade.
- The status bar reports the fist prompt while the hand is clenched.

## HUD
- Top bar: logo, UNDO, and XÓA buttons in a glass container with rounded pill styling.
- Status bar: fixed at the bottom, Orbitron, color changes by mode.
- Help tips: bottom-right gesture summary.
- Loading overlay: centered spinner until camera and hands are ready.

## Data flow
1. `getUserMedia()` opens a 1280x720 user-facing camera.
2. `processFrame()` mirrors landmarks, then sends each video frame to MediaPipe Hands with `requestAnimationFrame`.
3. Hand landmarks update gesture state.
4. Drawing gestures write to `strokes[]` and `bgLayer`.
5. Particles render directly on the main canvas.
6. `p.clear()` runs every frame so only persistent strokes, particles, UI, and video remain visible.

## Error handling
- If camera permission fails, show a visible camera-error overlay instead of a blank canvas.
- If Hands fails to load, keep the camera UI visible and report the missing dependency.
- If a gesture is ambiguous, do nothing rather than guessing.
- No silent failures for camera startup, MediaPipe initialization, or drawing-state resets.

## Testing
- Keep one small browser self-check in the HTML for helper math and geometry assumptions.
- Manually verify:
  - mirrored landmarks line up with the video,
  - two hands can draw independently,
  - dwell selection fires after 480 ms,
  - pinch-move updates stroke geometry,
  - fist-to-open5 clears strokes and spawns shards.

## Implementation constraint
- Everything stays in `neon-draw.html`; no extra source files, no build step, no framework wrapper.

# Random Terrain Generator

A command-line application for procedural terrain generation and visualization. The project creates altitude maps using random generation techniques and converts them into colored images, allowing users to visualize landscapes such as mountains, plains, valleys, lakes, and oceans.

The generation process is based on altitude values, where each height level is associated with a specific color from a customizable palette. This approach enables the creation of detailed terrain maps that can be easily adapted to different environments and visual styles.

## Features

* Procedural generation of terrain heightmaps.
* Custom color palette support for terrain visualization.
* Image generation from altitude data.
* Export of generated maps in image formats.
* Modular architecture for easy extension and maintenance.

## How It Works

The application generates a terrain represented by a grid of altitude values. Each altitude is mapped to a color through a palette system, creating a visual representation of the landscape. Lower regions can represent bodies of water, while higher regions are displayed using progressively lighter colors to simulate elevation.

The project is divided into independent modules responsible for:

* **Color Palette Management** – Handles color definitions and altitude-to-color mapping.
* **Image Processing** – Creates and exports images from pixel data.
* **Terrain Generation** – Produces procedural heightmaps through random generation algorithms.
* **Terrain Visualization** – Converts generated terrain data into colored images.

## Use Cases

* Terrain simulation and experimentation.
* Procedural content generation studies.
* Visualization of heightmap algorithms.
* Educational demonstrations of procedural generation concepts.

## Technologies

* C++
* Object-Oriented Programming
* Procedural Generation Techniques
* PPM Image Format

## Output Example

The generated output consists of terrain images where each pixel represents an altitude value. Different colors indicate different elevation levels, creating a clear and intuitive visualization of the generated landscape.

{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    alsa-lib
    curl
    freetype
    xorg.libX11
    xorg.libXext
    xorg.libXinerama
    xorg.libXrandr
    xorg.libXcursor
    xorg.libXcomposite
    libGL
    jack2
    fontconfig
    pkg-config
  ];
}

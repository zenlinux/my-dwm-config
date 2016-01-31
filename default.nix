{ pkgs ? import <nixpkgs> {} }:
  let
    stdenv = pkgs.stdenv;
  in
    stdenv.mkDerivation {
      name="NAME-0.1";
      src = ./.;
    buildInputs = with pkgs;[
      xlibs.libX11
      xlibs.libXft
      xlibs.libXinerama
      xlibs.xproto
    ];
}

# cd to this directory and run
# at the prompt $ nix-build . --run-env
# after that a simple make command will compile the program.

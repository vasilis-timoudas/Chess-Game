cmake_minimum_required(VERSION 3.14)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp piece.cpp piece.h pawn.cpp pawn.h rook.cpp rook.h knight.cpp knight.h bishop.cpp bishop.h queen.cpp queen.h king.cpp king.h empty.cpp empty.h board.cpp board.h game.cpp game.h)
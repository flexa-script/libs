// sound core lib
// MIT License
// Copyright (c) 2024 Carlos Eduardo de Borba Machado

namespace cp;

const MIN_VOLUME = 0f;
const MAX_VOLUME = 1f;

fun play_sound(path: string);
fun play_sound_once(path: string);
fun stop_sound();
fun set_volume(volume: float);

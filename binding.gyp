{
  "targets": [
    {
      "target_name": "filter_driver_control",
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "sources": [
        "src/filter_driver_control.cpp",
        "src/wrapper/filter_driver_control_wrapper.cpp",
        "src/wrapper/wrapper.cpp"
      ],
      "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
      "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
      "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"]
    }
  ]
}
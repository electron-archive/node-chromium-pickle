{
  "targets": [
    {
      "target_name": "pickle",
      "sources": [
        "src/main.cc",
        "src/pickle.cc",
        "src/pickle.h",
        "src/pickle_iterator_wrapper.cc",
        "src/pickle_iterator_wrapper.h",
        "src/pickle_wrapper.cc",
        "src/pickle_wrapper.h",
      ],
      "include_dirs": [ "." ],
      "dependencies": [ "<!(node -e \"require('native-mate')\")" ],
      "conditions": [
        ['OS=="win"', {
          'msvs_settings': {
            'VCLinkerTool': {
              'AdditionalOptions': [
                '/FORCE:MULTIPLE'
              ]
            },
            'VCCLCompilerTool': {
              'AdditionalOptions': [
                '/EHsc'
              ]
            }
          }
        }],
      ],
    }
  ]
}

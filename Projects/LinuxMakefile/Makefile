# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# build with "V=1" for verbose builds
ifeq ($(V), 1)
V_AT =
else
V_AT = @
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef PKG_CONFIG
  PKG_CONFIG=pkg-config
endif

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

JUCE_ARCH_LABEL := $(shell uname -m)

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) "-DLINUX=1" "-DDEBUG=1" "-D_DEBUG=1" "-DJUCER_LINUX_MAKE_B650AE49=1" "-DJUCE_APP_VERSION=3.14" "-DJUCE_APP_VERSION_HEX=0x30e00" $(shell $(PKG_CONFIG) --cflags alsa freetype2 fontconfig gl libcurl) -pthread -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/ASIO/common -I../../Source/ -I../../Source/Core -I../../Source/Core/Audio -I../../Source/Core/Audio/BuiltIn -I../../Source/Core/Audio/BuiltIn/SoundFont -I../../Source/Core/Audio/Instruments -I../../Source/Core/Audio/Transport -I../../Source/Core/Configuration -I../../Source/Core/Configuration/Resources -I../../Source/Core/Configuration/Resources/Models -I../../Source/Core/CommandPalette -I../../Source/Core/Midi -I../../Source/Core/Midi/Patterns -I../../Source/Core/Midi/Patterns/Modifiers -I../../Source/Core/Midi/Sequences -I../../Source/Core/Midi/Sequences/Events -I../../Source/Core/Network -I../../Source/Core/Network/Models -I../../Source/Core/Network/Requests -I../../Source/Core/Network/Services -I../../Source/Core/Serialization -I../../Source/Core/Tree -I../../Source/Core/Undo -I../../Source/Core/Undo/Actions -I../../Source/Core/VCS -I../../Source/Core/VCS/DiffLogic -I../../Source/Core/Workspace -I../../Source/UI/ -I../../Source/UI/Common -I../../Source/UI/Dialogs -I../../Source/UI/Headline -I../../Source/UI/Input -I../../Source/UI/Menus -I../../Source/UI/Menus/Base -I../../Source/UI/Menus/SelectionMenus -I../../Source/UI/Pages/Instruments -I../../Source/UI/Pages/Instruments/Editor -I../../Source/UI/Pages/Project -I../../Source/UI/Pages/Settings -I../../Source/UI/Pages/VCS -I../../Source/UI/Pages/Dashboard -I../../Source/UI/Popups -I../../Source/UI/Sequencer -I../../Source/UI/Sequencer/EditorPanels -I../../Source/UI/Sequencer/EditorPanels/AutomationEditor -I../../Source/UI/Sequencer/EditorPanels/VelocityEditor -I../../Source/UI/Sequencer/Header -I../../Source/UI/Sequencer/Helpers -I../../Source/UI/Sequencer/MiniMaps -I../../Source/UI/Sequencer/MiniMaps/AnnotationsMap -I../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap -I../../Source/UI/Sequencer/MiniMaps/PianoMap -I../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap -I../../Source/UI/Sequencer/PatternRoll -I../../Source/UI/Sequencer/PianoRoll -I../../Source/UI/Sequencer/Sidebars -I../../Source/UI/Themes $(CPPFLAGS)
  JUCE_CPPFLAGS_APP :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Build_LV2=0"
  JUCE_TARGET_APP := helio

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 -fpermissive -Wno-unknown-pragmas -Wno-reorder -Wno-dynamic-class-memaccess $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -L/usr/X11R6/lib/ $(shell $(PKG_CONFIG) --libs alsa freetype2 fontconfig gl libcurl) -fvisibility=hidden -lrt -ldl -lpthread $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(JUCE_TARGET_APP) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Tests)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Tests
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) "-DLINUX=1" "-DDEBUG=1" "-D_DEBUG=1" "-DJUCE_UNIT_TESTS=1" "-DJUCER_LINUX_MAKE_B650AE49=1" "-DJUCE_APP_VERSION=3.14" "-DJUCE_APP_VERSION_HEX=0x30e00" $(shell $(PKG_CONFIG) --cflags alsa freetype2 fontconfig gl libcurl) -pthread -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/ASIO/common -I../../Source/ -I../../Source/Core -I../../Source/Core/Audio -I../../Source/Core/Audio/BuiltIn -I../../Source/Core/Audio/BuiltIn/SoundFont -I../../Source/Core/Audio/Instruments -I../../Source/Core/Audio/Transport -I../../Source/Core/Configuration -I../../Source/Core/Configuration/Resources -I../../Source/Core/Configuration/Resources/Models -I../../Source/Core/CommandPalette -I../../Source/Core/Midi -I../../Source/Core/Midi/Patterns -I../../Source/Core/Midi/Patterns/Modifiers -I../../Source/Core/Midi/Sequences -I../../Source/Core/Midi/Sequences/Events -I../../Source/Core/Network -I../../Source/Core/Network/Models -I../../Source/Core/Network/Requests -I../../Source/Core/Network/Services -I../../Source/Core/Serialization -I../../Source/Core/Tree -I../../Source/Core/Undo -I../../Source/Core/Undo/Actions -I../../Source/Core/VCS -I../../Source/Core/VCS/DiffLogic -I../../Source/Core/Workspace -I../../Source/UI/ -I../../Source/UI/Common -I../../Source/UI/Dialogs -I../../Source/UI/Headline -I../../Source/UI/Input -I../../Source/UI/Menus -I../../Source/UI/Menus/Base -I../../Source/UI/Menus/SelectionMenus -I../../Source/UI/Pages/Instruments -I../../Source/UI/Pages/Instruments/Editor -I../../Source/UI/Pages/Project -I../../Source/UI/Pages/Settings -I../../Source/UI/Pages/VCS -I../../Source/UI/Pages/Dashboard -I../../Source/UI/Popups -I../../Source/UI/Sequencer -I../../Source/UI/Sequencer/EditorPanels -I../../Source/UI/Sequencer/EditorPanels/AutomationEditor -I../../Source/UI/Sequencer/EditorPanels/VelocityEditor -I../../Source/UI/Sequencer/Header -I../../Source/UI/Sequencer/Helpers -I../../Source/UI/Sequencer/MiniMaps -I../../Source/UI/Sequencer/MiniMaps/AnnotationsMap -I../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap -I../../Source/UI/Sequencer/MiniMaps/PianoMap -I../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap -I../../Source/UI/Sequencer/PatternRoll -I../../Source/UI/Sequencer/PianoRoll -I../../Source/UI/Sequencer/Sidebars -I../../Source/UI/Themes $(CPPFLAGS)
  JUCE_CPPFLAGS_APP :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Build_LV2=0"
  JUCE_TARGET_APP := helio

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 -fpermissive -Wno-unknown-pragmas -Wno-reorder -Wno-dynamic-class-memaccess $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -L/usr/X11R6/lib/ $(shell $(PKG_CONFIG) --libs alsa freetype2 fontconfig gl libcurl) -fvisibility=hidden -lrt -ldl -lpthread $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(JUCE_TARGET_APP) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release32)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release32
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -m32
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) "-DLINUX=1" "-DNDEBUG=1" "-DJUCER_LINUX_MAKE_B650AE49=1" "-DJUCE_APP_VERSION=3.14" "-DJUCE_APP_VERSION_HEX=0x30e00" $(shell $(PKG_CONFIG) --cflags alsa freetype2 fontconfig gl libcurl) -pthread -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/ASIO/common -I../../Source/ -I../../Source/Core -I../../Source/Core/Audio -I../../Source/Core/Audio/BuiltIn -I../../Source/Core/Audio/BuiltIn/SoundFont -I../../Source/Core/Audio/Instruments -I../../Source/Core/Audio/Transport -I../../Source/Core/Configuration -I../../Source/Core/Configuration/Resources -I../../Source/Core/Configuration/Resources/Models -I../../Source/Core/CommandPalette -I../../Source/Core/Midi -I../../Source/Core/Midi/Patterns -I../../Source/Core/Midi/Patterns/Modifiers -I../../Source/Core/Midi/Sequences -I../../Source/Core/Midi/Sequences/Events -I../../Source/Core/Network -I../../Source/Core/Network/Models -I../../Source/Core/Network/Requests -I../../Source/Core/Network/Services -I../../Source/Core/Serialization -I../../Source/Core/Tree -I../../Source/Core/Undo -I../../Source/Core/Undo/Actions -I../../Source/Core/VCS -I../../Source/Core/VCS/DiffLogic -I../../Source/Core/Workspace -I../../Source/UI/ -I../../Source/UI/Common -I../../Source/UI/Dialogs -I../../Source/UI/Headline -I../../Source/UI/Input -I../../Source/UI/Menus -I../../Source/UI/Menus/Base -I../../Source/UI/Menus/SelectionMenus -I../../Source/UI/Pages/Instruments -I../../Source/UI/Pages/Instruments/Editor -I../../Source/UI/Pages/Project -I../../Source/UI/Pages/Settings -I../../Source/UI/Pages/VCS -I../../Source/UI/Pages/Dashboard -I../../Source/UI/Popups -I../../Source/UI/Sequencer -I../../Source/UI/Sequencer/EditorPanels -I../../Source/UI/Sequencer/EditorPanels/AutomationEditor -I../../Source/UI/Sequencer/EditorPanels/VelocityEditor -I../../Source/UI/Sequencer/Header -I../../Source/UI/Sequencer/Helpers -I../../Source/UI/Sequencer/MiniMaps -I../../Source/UI/Sequencer/MiniMaps/AnnotationsMap -I../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap -I../../Source/UI/Sequencer/MiniMaps/PianoMap -I../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap -I../../Source/UI/Sequencer/PatternRoll -I../../Source/UI/Sequencer/PianoRoll -I../../Source/UI/Sequencer/Sidebars -I../../Source/UI/Themes $(CPPFLAGS)
  JUCE_CPPFLAGS_APP :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Build_LV2=0"
  JUCE_TARGET_APP := helio

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 -flto -fpermissive -Wno-unknown-pragmas -Wno-reorder -Wno-dynamic-class-memaccess $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -L/usr/X11R6/lib/ $(shell $(PKG_CONFIG) --libs alsa freetype2 fontconfig gl libcurl) -fvisibility=hidden -flto -lrt -ldl -lpthread $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(JUCE_TARGET_APP) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release64)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release64
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -m64
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) "-DLINUX=1" "-DNDEBUG=1" "-DJUCER_LINUX_MAKE_B650AE49=1" "-DJUCE_APP_VERSION=3.14" "-DJUCE_APP_VERSION_HEX=0x30e00" $(shell $(PKG_CONFIG) --cflags alsa freetype2 fontconfig gl libcurl) -pthread -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../Projucer/JuceLibraryCode -I../../ThirdParty/JUCE/modules -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/VST3_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/serd -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sord/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/sratom -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lilv/src -I../../ThirdParty/JUCE/modules/juce_audio_processors/format_types/LV2_SDK/lv2 -I../../ThirdParty/ASIO/common -I../../Source/ -I../../Source/Core -I../../Source/Core/Audio -I../../Source/Core/Audio/BuiltIn -I../../Source/Core/Audio/BuiltIn/SoundFont -I../../Source/Core/Audio/Instruments -I../../Source/Core/Audio/Transport -I../../Source/Core/Configuration -I../../Source/Core/Configuration/Resources -I../../Source/Core/Configuration/Resources/Models -I../../Source/Core/CommandPalette -I../../Source/Core/Midi -I../../Source/Core/Midi/Patterns -I../../Source/Core/Midi/Patterns/Modifiers -I../../Source/Core/Midi/Sequences -I../../Source/Core/Midi/Sequences/Events -I../../Source/Core/Network -I../../Source/Core/Network/Models -I../../Source/Core/Network/Requests -I../../Source/Core/Network/Services -I../../Source/Core/Serialization -I../../Source/Core/Tree -I../../Source/Core/Undo -I../../Source/Core/Undo/Actions -I../../Source/Core/VCS -I../../Source/Core/VCS/DiffLogic -I../../Source/Core/Workspace -I../../Source/UI/ -I../../Source/UI/Common -I../../Source/UI/Dialogs -I../../Source/UI/Headline -I../../Source/UI/Input -I../../Source/UI/Menus -I../../Source/UI/Menus/Base -I../../Source/UI/Menus/SelectionMenus -I../../Source/UI/Pages/Instruments -I../../Source/UI/Pages/Instruments/Editor -I../../Source/UI/Pages/Project -I../../Source/UI/Pages/Settings -I../../Source/UI/Pages/VCS -I../../Source/UI/Pages/Dashboard -I../../Source/UI/Popups -I../../Source/UI/Sequencer -I../../Source/UI/Sequencer/EditorPanels -I../../Source/UI/Sequencer/EditorPanels/AutomationEditor -I../../Source/UI/Sequencer/EditorPanels/VelocityEditor -I../../Source/UI/Sequencer/Header -I../../Source/UI/Sequencer/Helpers -I../../Source/UI/Sequencer/MiniMaps -I../../Source/UI/Sequencer/MiniMaps/AnnotationsMap -I../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap -I../../Source/UI/Sequencer/MiniMaps/PianoMap -I../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap -I../../Source/UI/Sequencer/PatternRoll -I../../Source/UI/Sequencer/PianoRoll -I../../Source/UI/Sequencer/Sidebars -I../../Source/UI/Themes $(CPPFLAGS)
  JUCE_CPPFLAGS_APP :=  "-DJucePlugin_Build_VST=0" "-DJucePlugin_Build_VST3=0" "-DJucePlugin_Build_AU=0" "-DJucePlugin_Build_AUv3=0" "-DJucePlugin_Build_AAX=0" "-DJucePlugin_Build_Standalone=0" "-DJucePlugin_Build_Unity=0" "-DJucePlugin_Build_LV2=0"
  JUCE_TARGET_APP := helio

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 -flto -fpermissive -Wno-unknown-pragmas -Wno-reorder -Wno-dynamic-class-memaccess $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -L/usr/X11R6/lib/ $(shell $(PKG_CONFIG) --libs alsa freetype2 fontconfig gl libcurl) -fvisibility=hidden -flto -lrt -ldl -lpthread $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(JUCE_TARGET_APP) $(JUCE_OBJDIR)
endif

OBJECTS_APP := \
  $(JUCE_OBJDIR)/SoundFont2Sound_ecd8c5be.o \
  $(JUCE_OBJDIR)/SoundFontSound_ebb45918.o \
  $(JUCE_OBJDIR)/SoundFontSynth_92a9ecc5.o \
  $(JUCE_OBJDIR)/InternalIODevicesPluginFormat_51a1e4d8.o \
  $(JUCE_OBJDIR)/BuiltInSynthsPluginFormat_26109c78.o \
  $(JUCE_OBJDIR)/DefaultSynthAudioPlugin_e8c52062.o \
  $(JUCE_OBJDIR)/DefaultSynth_4e590d91.o \
  $(JUCE_OBJDIR)/MetronomeSynthAudioPlugin_5f44ab93.o \
  $(JUCE_OBJDIR)/MetronomeSynth_e1009700.o \
  $(JUCE_OBJDIR)/SoundFontSynthAudioPlugin_26648fdf.o \
  $(JUCE_OBJDIR)/Instrument_bb3fff74.o \
  $(JUCE_OBJDIR)/OrchestraPit_a67292bb.o \
  $(JUCE_OBJDIR)/PluginScanner_cf690128.o \
  $(JUCE_OBJDIR)/SerializablePluginDescription_dc94bde7.o \
  $(JUCE_OBJDIR)/MidiRecorder_1cdf45af.o \
  $(JUCE_OBJDIR)/PlayerThread_2ab68fb.o \
  $(JUCE_OBJDIR)/RendererThread_511aa99d.o \
  $(JUCE_OBJDIR)/Transport_931cdbc3.o \
  $(JUCE_OBJDIR)/AudioCore_ec8fdd75.o \
  $(JUCE_OBJDIR)/AudioMonitor_a48c30ce.o \
  $(JUCE_OBJDIR)/Arpeggiator_9050a3c8.o \
  $(JUCE_OBJDIR)/Chord_15b4b66b.o \
  $(JUCE_OBJDIR)/ColourScheme_ff9a6a2c.o \
  $(JUCE_OBJDIR)/HotkeyScheme_537c7fd2.o \
  $(JUCE_OBJDIR)/KeyboardMapping_f6615ef6.o \
  $(JUCE_OBJDIR)/Meter_9bd2f718.o \
  $(JUCE_OBJDIR)/Scale_63cf8c59.o \
  $(JUCE_OBJDIR)/Temperament_c32247ed.o \
  $(JUCE_OBJDIR)/Translation_14c87ec0.o \
  $(JUCE_OBJDIR)/ConfigurationResourceCollection_f38be158.o \
  $(JUCE_OBJDIR)/ArpeggiatorsCollection_f7d16cec.o \
  $(JUCE_OBJDIR)/ChordsCollection_a3d7c529.o \
  $(JUCE_OBJDIR)/ColourSchemesCollection_bf9a8ab6.o \
  $(JUCE_OBJDIR)/HotkeySchemesCollection_1a3a9150.o \
  $(JUCE_OBJDIR)/KeyboardMappingsCollection_fbfdc47e.o \
  $(JUCE_OBJDIR)/MetersCollection_5b5e465c.o \
  $(JUCE_OBJDIR)/ScalesCollection_573d8e7b.o \
  $(JUCE_OBJDIR)/TemperamentsCollection_72fe2fa7.o \
  $(JUCE_OBJDIR)/TranslationsCollection_8de586f4.o \
  $(JUCE_OBJDIR)/Config_db7b8b0c.o \
  $(JUCE_OBJDIR)/UserInterfaceFlags_6a384243.o \
  $(JUCE_OBJDIR)/CommandPaletteActionsProvider_5f29070.o \
  $(JUCE_OBJDIR)/CommandPaletteCommonActions_8c32d834.o \
  $(JUCE_OBJDIR)/CommandPaletteChordConstructor_f036fca6.o \
  $(JUCE_OBJDIR)/CommandPaletteMoveNotesMenu_a5c6c811.o \
  $(JUCE_OBJDIR)/CommandPaletteProjectsList_341ccf60.o \
  $(JUCE_OBJDIR)/CommandPaletteTimelineEvents_2f77aa22.o \
  $(JUCE_OBJDIR)/MarkovModel_f119297.o \
  $(JUCE_OBJDIR)/GeneratedSequenceBuilder_4df1380d.o \
  $(JUCE_OBJDIR)/Clip_5929fe7f.o \
  $(JUCE_OBJDIR)/Pattern_a3a86b8b.o \
  $(JUCE_OBJDIR)/AnnotationEvent_8fa9bdd9.o \
  $(JUCE_OBJDIR)/AutomationEvent_5ea238f1.o \
  $(JUCE_OBJDIR)/KeySignatureEvent_80a740ef.o \
  $(JUCE_OBJDIR)/MidiEvent_cfd604e7.o \
  $(JUCE_OBJDIR)/Note_42fe2f4e.o \
  $(JUCE_OBJDIR)/TimeSignatureEvent_5ddd998b.o \
  $(JUCE_OBJDIR)/AnnotationsSequence_1997bf8b.o \
  $(JUCE_OBJDIR)/AutomationSequence_84d9de3c.o \
  $(JUCE_OBJDIR)/KeySignaturesSequence_6a59f1a1.o \
  $(JUCE_OBJDIR)/MidiSequence_310d4486.o \
  $(JUCE_OBJDIR)/PianoSequence_e11a82f0.o \
  $(JUCE_OBJDIR)/TimeSignaturesSequence_5fa7c98d.o \
  $(JUCE_OBJDIR)/TimeSignaturesAggregator_b0273fd5.o \
  $(JUCE_OBJDIR)/MidiTrack_6604020d.o \
  $(JUCE_OBJDIR)/BackendRequest_7a512d9e.o \
  $(JUCE_OBJDIR)/UserConfigSyncThread_281a0595.o \
  $(JUCE_OBJDIR)/ProjectCloneThread_838580b1.o \
  $(JUCE_OBJDIR)/ProjectDeleteThread_df81aeb5.o \
  $(JUCE_OBJDIR)/RevisionsSyncHelpers_6a382a95.o \
  $(JUCE_OBJDIR)/RevisionsSyncThread_7ea15884.o \
  $(JUCE_OBJDIR)/ProjectSyncService_904c332a.o \
  $(JUCE_OBJDIR)/ResourceSyncService_3cb65bad.o \
  $(JUCE_OBJDIR)/SessionService_7b0612a8.o \
  $(JUCE_OBJDIR)/NetworkServices_34098b24.o \
  $(JUCE_OBJDIR)/Autosaver_8ecb1540.o \
  $(JUCE_OBJDIR)/Document_25ea426b.o \
  $(JUCE_OBJDIR)/DocumentHelpers_16095e24.o \
  $(JUCE_OBJDIR)/SerializedData_9265d6de.o \
  $(JUCE_OBJDIR)/BinarySerializer_c8c2cac3.o \
  $(JUCE_OBJDIR)/JsonSerializer_97d7162a.o \
  $(JUCE_OBJDIR)/XmlSerializer_489b3c03.o \
  $(JUCE_OBJDIR)/AutomationTrackNode_e0dff3f6.o \
  $(JUCE_OBJDIR)/InstrumentNode_69832033.o \
  $(JUCE_OBJDIR)/MidiTrackNode_12dce26c.o \
  $(JUCE_OBJDIR)/OrchestraPitNode_9ee364ba.o \
  $(JUCE_OBJDIR)/PatternEditorNode_ffd5345f.o \
  $(JUCE_OBJDIR)/PianoTrackNode_f7a15ace.o \
  $(JUCE_OBJDIR)/ProjectMetadata_8da17f48.o \
  $(JUCE_OBJDIR)/ProjectTimeline_9655ff5a.o \
  $(JUCE_OBJDIR)/ProjectNode_8b4c229b.o \
  $(JUCE_OBJDIR)/RootNode_a3140dee.o \
  $(JUCE_OBJDIR)/SettingsNode_1b17d5af.o \
  $(JUCE_OBJDIR)/TrackGroupNode_96578b40.o \
  $(JUCE_OBJDIR)/TreeNode_364484aa.o \
  $(JUCE_OBJDIR)/TreeNodeSerializer_1d017f1c.o \
  $(JUCE_OBJDIR)/VersionControlNode_a601d931.o \
  $(JUCE_OBJDIR)/AnnotationEventActions_e2dc4268.o \
  $(JUCE_OBJDIR)/AutomationTrackActions_7e56b4ff.o \
  $(JUCE_OBJDIR)/AutomationEventActions_ba8f9c50.o \
  $(JUCE_OBJDIR)/KeySignatureEventActions_3b0ee412.o \
  $(JUCE_OBJDIR)/MidiTrackActions_47b06bc9.o \
  $(JUCE_OBJDIR)/NoteActions_b5a2e99f.o \
  $(JUCE_OBJDIR)/PatternActions_60a33363.o \
  $(JUCE_OBJDIR)/PianoTrackActions_78338acf.o \
  $(JUCE_OBJDIR)/ProjectMetadataActions_5f57158b.o \
  $(JUCE_OBJDIR)/TimeSignatureEventActions_c6f6be42.o \
  $(JUCE_OBJDIR)/UndoStack_c8cfe6ea.o \
  $(JUCE_OBJDIR)/AutomationTrackDiffLogic_d3a28db5.o \
  $(JUCE_OBJDIR)/DiffLogic_e39316b3.o \
  $(JUCE_OBJDIR)/PatternDiffHelpers_2a43df40.o \
  $(JUCE_OBJDIR)/PianoTrackDiffLogic_1fe33611.o \
  $(JUCE_OBJDIR)/ProjectInfoDiffLogic_85d6d922.o \
  $(JUCE_OBJDIR)/ProjectTimelineDiffLogic_dd926f6f.o \
  $(JUCE_OBJDIR)/Delta_dc1eed28.o \
  $(JUCE_OBJDIR)/Diff_3af4c61f.o \
  $(JUCE_OBJDIR)/Head_fe3c227a.o \
  $(JUCE_OBJDIR)/RemoteCache_d9eaca0c.o \
  $(JUCE_OBJDIR)/Revision_ddbb1c75.o \
  $(JUCE_OBJDIR)/RevisionItem_7e6e5a28.o \
  $(JUCE_OBJDIR)/Snapshot_f0be1dde.o \
  $(JUCE_OBJDIR)/StashesRepository_bb52fdfd.o \
  $(JUCE_OBJDIR)/VersionControl_bc67ed3f.o \
  $(JUCE_OBJDIR)/NavigationHistory_39a99bf.o \
  $(JUCE_OBJDIR)/RecentProjectInfo_9bf049eb.o \
  $(JUCE_OBJDIR)/SyncedConfigurationInfo_f19402c9.o \
  $(JUCE_OBJDIR)/UserSessionInfo_61ea4378.o \
  $(JUCE_OBJDIR)/UserProfile_63ae89bd.o \
  $(JUCE_OBJDIR)/Workspace_e70d39f4.o \
  $(JUCE_OBJDIR)/App_9f51319a.o \
  $(JUCE_OBJDIR)/ColourButton_d92c95b0.o \
  $(JUCE_OBJDIR)/ColourSwatches_e2a4628.o \
  $(JUCE_OBJDIR)/CommandIDs_ca65c4df.o \
  $(JUCE_OBJDIR)/ColourIDs_78db4164.o \
  $(JUCE_OBJDIR)/DraggingListBoxComponent_34f40031.o \
  $(JUCE_OBJDIR)/KeySelector_58be6196.o \
  $(JUCE_OBJDIR)/MobileComboBox_bdac55f1.o \
  $(JUCE_OBJDIR)/ModeIndicatorComponent_7338ae83.o \
  $(JUCE_OBJDIR)/PlayButton_38579458.o \
  $(JUCE_OBJDIR)/PluginWindow_66751815.o \
  $(JUCE_OBJDIR)/RadioButton_45b0c9c5.o \
  $(JUCE_OBJDIR)/ScaleEditor_6bc10d0f.o \
  $(JUCE_OBJDIR)/SpectralLogo_f6755a41.o \
  $(JUCE_OBJDIR)/TransportControlComponent_4d74e1.o \
  $(JUCE_OBJDIR)/ViewportFitProxyComponent_a93fb792.o \
  $(JUCE_OBJDIR)/DialogBase_ff1ce7b9.o \
  $(JUCE_OBJDIR)/AnnotationDialog_bb76a597.o \
  $(JUCE_OBJDIR)/KeySignatureDialog_b4559c41.o \
  $(JUCE_OBJDIR)/ModalDialogConfirmation_23a5c174.o \
  $(JUCE_OBJDIR)/ModalDialogInput_6af917b5.o \
  $(JUCE_OBJDIR)/RenderDialog_d54ea4be.o \
  $(JUCE_OBJDIR)/TempoDialog_19dcad8d.o \
  $(JUCE_OBJDIR)/TimeSignatureDialog_7d6669dd.o \
  $(JUCE_OBJDIR)/TrackPropertiesDialog_5e178150.o \
  $(JUCE_OBJDIR)/Headline_2606435d.o \
  $(JUCE_OBJDIR)/HeadlineDropdown_494f430e.o \
  $(JUCE_OBJDIR)/HeadlineItem_cd7bcd10.o \
  $(JUCE_OBJDIR)/HeadlineContextMenuController_eb2fb3d7.o \
  $(JUCE_OBJDIR)/MultiTouchController_63afb603.o \
  $(JUCE_OBJDIR)/MenuItemComponent_2eff5284.o \
  $(JUCE_OBJDIR)/MenuPanel_ee874d5e.o \
  $(JUCE_OBJDIR)/AudioPluginSelectionMenu_3e54c8bc.o \
  $(JUCE_OBJDIR)/InstrumentNodeSelectionMenu_d61c1e72.o \
  $(JUCE_OBJDIR)/PatternRollSelectionMenu_1f7a27b8.o \
  $(JUCE_OBJDIR)/PianoRollSelectionMenu_69b358df.o \
  $(JUCE_OBJDIR)/VersionControlHistorySelectionMenu_55cc6e76.o \
  $(JUCE_OBJDIR)/VersionControlStageSelectionMenu_d66783cc.o \
  $(JUCE_OBJDIR)/InstrumentMenu_4fd005bd.o \
  $(JUCE_OBJDIR)/ClipMenu_13ec0da6.o \
  $(JUCE_OBJDIR)/OrchestraPitMenu_2065d304.o \
  $(JUCE_OBJDIR)/PatternsMenu_1f8f0d39.o \
  $(JUCE_OBJDIR)/ProjectMenu_5ab725eb.o \
  $(JUCE_OBJDIR)/TimelineMenu_2c071c97.o \
  $(JUCE_OBJDIR)/VersionControlMenu_cb7aa03b.o \
  $(JUCE_OBJDIR)/WorkspaceMenu_25163be7.o \
  $(JUCE_OBJDIR)/Dashboard_81cfc8dc.o \
  $(JUCE_OBJDIR)/DashboardMenu_bcc0f5b.o \
  $(JUCE_OBJDIR)/AudioPluginEditorPage_d260a64d.o \
  $(JUCE_OBJDIR)/InstrumentEditor_e7548c16.o \
  $(JUCE_OBJDIR)/InstrumentEditorConnector_813d7c21.o \
  $(JUCE_OBJDIR)/InstrumentComponent_f2b63e3e.o \
  $(JUCE_OBJDIR)/InstrumentEditorPin_387238a9.o \
  $(JUCE_OBJDIR)/KeyboardMappingPage_6ce5b77e.o \
  $(JUCE_OBJDIR)/AudioPluginsListComponent_27b60455.o \
  $(JUCE_OBJDIR)/InstrumentsListComponent_2905dadd.o \
  $(JUCE_OBJDIR)/OrchestraPitPage_52882f47.o \
  $(JUCE_OBJDIR)/ProjectPage_f686b2d5.o \
  $(JUCE_OBJDIR)/AudioSettings_716d894.o \
  $(JUCE_OBJDIR)/ComponentsList_fad5fa03.o \
  $(JUCE_OBJDIR)/SettingsFrameWrapper_27c0b958.o \
  $(JUCE_OBJDIR)/SettingsPage_ab9efe01.o \
  $(JUCE_OBJDIR)/SyncSettings_7b017e8d.o \
  $(JUCE_OBJDIR)/SyncSettingsItem_6f05f040.o \
  $(JUCE_OBJDIR)/ThemeSettings_1f7e5e07.o \
  $(JUCE_OBJDIR)/ThemeSettingsItem_c2b282ba.o \
  $(JUCE_OBJDIR)/TranslationSettings_f4a7f26f.o \
  $(JUCE_OBJDIR)/TranslationSettingsItem_6aba322.o \
  $(JUCE_OBJDIR)/UserInterfaceSettings_8b19486c.o \
  $(JUCE_OBJDIR)/HistoryComponent_115e47f9.o \
  $(JUCE_OBJDIR)/RevisionComponent_51e2497c.o \
  $(JUCE_OBJDIR)/RevisionConnectorComponent_a2024cdb.o \
  $(JUCE_OBJDIR)/RevisionItemComponent_8654a029.o \
  $(JUCE_OBJDIR)/RevisionTooltipComponent_c893ee65.o \
  $(JUCE_OBJDIR)/RevisionTreeComponent_2b8f217e.o \
  $(JUCE_OBJDIR)/StageComponent_f36288f.o \
  $(JUCE_OBJDIR)/VersionControlEditor_c12aa262.o \
  $(JUCE_OBJDIR)/CommandPalette_cdcff526.o \
  $(JUCE_OBJDIR)/ArpPreviewTool_98f46997.o \
  $(JUCE_OBJDIR)/ChordPreviewTool_422991ba.o \
  $(JUCE_OBJDIR)/RescalePreviewTool_6e22f57f.o \
  $(JUCE_OBJDIR)/ModalCallout_e0f2fbf9.o \
  $(JUCE_OBJDIR)/PopupButton_5c5e0092.o \
  $(JUCE_OBJDIR)/PopupCustomButton_6d33e2a3.o \
  $(JUCE_OBJDIR)/ProgressTooltip_f470232a.o \
  $(JUCE_OBJDIR)/TooltipContainer_52ddacf4.o \
  $(JUCE_OBJDIR)/MarkovEditorComponent_5beab128.o \
  $(JUCE_OBJDIR)/AutomationEditor_10bbc76.o \
  $(JUCE_OBJDIR)/AutomationCurveHelper_d482275e.o \
  $(JUCE_OBJDIR)/AutomationCurveEventComponent_25e511b3.o \
  $(JUCE_OBJDIR)/AutomationCurveEventsConnector_1577264e.o \
  $(JUCE_OBJDIR)/AutomationStepEventComponent_5a4a4178.o \
  $(JUCE_OBJDIR)/AutomationStepEventsConnector_6db7ef29.o \
  $(JUCE_OBJDIR)/VelocityEditor_10f56f76.o \
  $(JUCE_OBJDIR)/EditorPanelsScroller_377f2319.o \
  $(JUCE_OBJDIR)/HeaderSelectionIndicator_5aed2562.o \
  $(JUCE_OBJDIR)/RollHeader_b1badd3c.o \
  $(JUCE_OBJDIR)/Playhead_49aa3d26.o \
  $(JUCE_OBJDIR)/CutPointMark_e432a7df.o \
  $(JUCE_OBJDIR)/RollExpandMark_91f57428.o \
  $(JUCE_OBJDIR)/KnifeToolHelper_d68a471.o \
  $(JUCE_OBJDIR)/MergingEventsConnector_d1b12a43.o \
  $(JUCE_OBJDIR)/TimelineWarningMarker_6d5c36fb.o \
  $(JUCE_OBJDIR)/PatternOperations_aae46f62.o \
  $(JUCE_OBJDIR)/SequencerOperations_4fa1bea3.o \
  $(JUCE_OBJDIR)/AutomationCurveClipComponent_2806cdb1.o \
  $(JUCE_OBJDIR)/AutomationStepsClipComponent_ae8db279.o \
  $(JUCE_OBJDIR)/PianoClipComponent_726e7f60.o \
  $(JUCE_OBJDIR)/ClipComponent_3c63e97b.o \
  $(JUCE_OBJDIR)/DummyClipComponent_76f3c1e1.o \
  $(JUCE_OBJDIR)/PatternRoll_9707f85b.o \
  $(JUCE_OBJDIR)/HighlightingScheme_959e38f6.o \
  $(JUCE_OBJDIR)/NoteComponent_465c17d2.o \
  $(JUCE_OBJDIR)/NoteNameGuidesBar_93845a26.o \
  $(JUCE_OBJDIR)/NoteResizerLeft_c3d11e3a.o \
  $(JUCE_OBJDIR)/NoteResizerRight_f3a02f93.o \
  $(JUCE_OBJDIR)/PianoRoll_c125538d.o \
  $(JUCE_OBJDIR)/SequencerSidebarLeft_1fad65fa.o \
  $(JUCE_OBJDIR)/SequencerSidebarRight_134cdfd3.o \
  $(JUCE_OBJDIR)/WaveformAudioMonitorComponent_f44a773e.o \
  $(JUCE_OBJDIR)/AnnotationLargeComponent_d95ee3c1.o \
  $(JUCE_OBJDIR)/AnnotationSmallComponent_f4fc5575.o \
  $(JUCE_OBJDIR)/AnnotationsProjectMap_e8c59661.o \
  $(JUCE_OBJDIR)/KeySignatureLargeComponent_7ce9b141.o \
  $(JUCE_OBJDIR)/KeySignatureSmallComponent_988722f5.o \
  $(JUCE_OBJDIR)/KeySignaturesProjectMap_4269b8e1.o \
  $(JUCE_OBJDIR)/PianoProjectMap_b13b64c1.o \
  $(JUCE_OBJDIR)/TimeSignatureLargeComponent_9bda06b.o \
  $(JUCE_OBJDIR)/TimeSignatureSmallComponent_255b121f.o \
  $(JUCE_OBJDIR)/TimeSignaturesProjectMap_407e29f7.o \
  $(JUCE_OBJDIR)/ProjectMapsScroller_c98b46a3.o \
  $(JUCE_OBJDIR)/RollBase_a5b0a008.o \
  $(JUCE_OBJDIR)/RollEditMode_11c8f104.o \
  $(JUCE_OBJDIR)/LassoListeners_6bea92bf.o \
  $(JUCE_OBJDIR)/RollChildComponentBase_d38a0ee9.o \
  $(JUCE_OBJDIR)/SelectionComponent_9dff102b.o \
  $(JUCE_OBJDIR)/SequencerLayout_58e2f98b.o \
  $(JUCE_OBJDIR)/HelioTheme_d6ec9067.o \
  $(JUCE_OBJDIR)/Icons_7879bcb1.o \
  $(JUCE_OBJDIR)/ViewportKineticSlider_45304cab.o \
  $(JUCE_OBJDIR)/MainLayout_4f58d3f.o \
  $(JUCE_OBJDIR)/Common_6ff75bf4.o \
  $(JUCE_OBJDIR)/BinaryData_7821001c.o \
  $(JUCE_OBJDIR)/include_juce_audio_basics_68629202.o \
  $(JUCE_OBJDIR)/include_juce_audio_devices_477c5a4a.o \
  $(JUCE_OBJDIR)/include_juce_audio_formats_fa635d49.o \
  $(JUCE_OBJDIR)/include_juce_audio_processors_6c50941e.o \
  $(JUCE_OBJDIR)/include_juce_audio_processors_ara_668730af.o \
  $(JUCE_OBJDIR)/include_juce_audio_processors_lv2_libs_fc0f5b50.o \
  $(JUCE_OBJDIR)/include_juce_core_9b124993.o \
  $(JUCE_OBJDIR)/include_juce_core_CompilationTime_ce9235e4.o \
  $(JUCE_OBJDIR)/include_juce_data_structures_eb02bd2b.o \
  $(JUCE_OBJDIR)/include_juce_events_23f77a4d.o \
  $(JUCE_OBJDIR)/include_juce_graphics_82dd76ff.o \
  $(JUCE_OBJDIR)/include_juce_graphics_Harfbuzz_774084ea.o \
  $(JUCE_OBJDIR)/include_juce_graphics_Sheenbidi_1ea0f505.o \
  $(JUCE_OBJDIR)/include_juce_gui_basics_d3ae9f3d.o \
  $(JUCE_OBJDIR)/include_juce_gui_extra_3bdb3d62.o \
  $(JUCE_OBJDIR)/include_juce_opengl_1ea9a6e3.o \

.PHONY: clean all strip

all : $(JUCE_OUTDIR)/$(JUCE_TARGET_APP)

$(JUCE_OUTDIR)/$(JUCE_TARGET_APP) : $(OBJECTS_APP) $(JUCE_OBJDIR)/execinfo.cmd $(RESOURCES)
	@command -v $(PKG_CONFIG) >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@$(PKG_CONFIG) --print-errors alsa freetype2 fontconfig gl libcurl
	@echo Linking "Helio - App"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_APP) $(OBJECTS_APP) $(JUCE_LDFLAGS) $(shell cat $(JUCE_OBJDIR)/execinfo.cmd) $(JUCE_LDFLAGS_APP) $(RESOURCES) $(TARGET_ARCH)

$(JUCE_OBJDIR)/SoundFont2Sound_ecd8c5be.o: ../../Source/Core/Audio/BuiltIn/SoundFont/SoundFont2Sound.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SoundFont2Sound.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SoundFontSound_ebb45918.o: ../../Source/Core/Audio/BuiltIn/SoundFont/SoundFontSound.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SoundFontSound.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SoundFontSynth_92a9ecc5.o: ../../Source/Core/Audio/BuiltIn/SoundFont/SoundFontSynth.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SoundFontSynth.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InternalIODevicesPluginFormat_51a1e4d8.o: ../../Source/Core/Audio/BuiltIn/InternalIODevicesPluginFormat.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InternalIODevicesPluginFormat.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BuiltInSynthsPluginFormat_26109c78.o: ../../Source/Core/Audio/BuiltIn/BuiltInSynthsPluginFormat.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling BuiltInSynthsPluginFormat.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DefaultSynthAudioPlugin_e8c52062.o: ../../Source/Core/Audio/BuiltIn/DefaultSynthAudioPlugin.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DefaultSynthAudioPlugin.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DefaultSynth_4e590d91.o: ../../Source/Core/Audio/BuiltIn/DefaultSynth.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DefaultSynth.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MetronomeSynthAudioPlugin_5f44ab93.o: ../../Source/Core/Audio/BuiltIn/MetronomeSynthAudioPlugin.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MetronomeSynthAudioPlugin.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MetronomeSynth_e1009700.o: ../../Source/Core/Audio/BuiltIn/MetronomeSynth.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MetronomeSynth.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SoundFontSynthAudioPlugin_26648fdf.o: ../../Source/Core/Audio/BuiltIn/SoundFontSynthAudioPlugin.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SoundFontSynthAudioPlugin.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Instrument_bb3fff74.o: ../../Source/Core/Audio/Instruments/Instrument.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Instrument.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/OrchestraPit_a67292bb.o: ../../Source/Core/Audio/Instruments/OrchestraPit.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling OrchestraPit.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginScanner_cf690128.o: ../../Source/Core/Audio/Instruments/PluginScanner.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PluginScanner.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SerializablePluginDescription_dc94bde7.o: ../../Source/Core/Audio/Instruments/SerializablePluginDescription.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SerializablePluginDescription.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiRecorder_1cdf45af.o: ../../Source/Core/Audio/Transport/MidiRecorder.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiRecorder.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PlayerThread_2ab68fb.o: ../../Source/Core/Audio/Transport/PlayerThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PlayerThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RendererThread_511aa99d.o: ../../Source/Core/Audio/Transport/RendererThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RendererThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Transport_931cdbc3.o: ../../Source/Core/Audio/Transport/Transport.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Transport.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioCore_ec8fdd75.o: ../../Source/Core/Audio/AudioCore.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioCore.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioMonitor_a48c30ce.o: ../../Source/Core/Audio/AudioMonitor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioMonitor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Arpeggiator_9050a3c8.o: ../../Source/Core/Configuration/Resources/Models/Arpeggiator.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Arpeggiator.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Chord_15b4b66b.o: ../../Source/Core/Configuration/Resources/Models/Chord.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Chord.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ColourScheme_ff9a6a2c.o: ../../Source/Core/Configuration/Resources/Models/ColourScheme.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ColourScheme.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HotkeyScheme_537c7fd2.o: ../../Source/Core/Configuration/Resources/Models/HotkeyScheme.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HotkeyScheme.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeyboardMapping_f6615ef6.o: ../../Source/Core/Configuration/Resources/Models/KeyboardMapping.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeyboardMapping.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Meter_9bd2f718.o: ../../Source/Core/Configuration/Resources/Models/Meter.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Meter.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Scale_63cf8c59.o: ../../Source/Core/Configuration/Resources/Models/Scale.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Scale.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Temperament_c32247ed.o: ../../Source/Core/Configuration/Resources/Models/Temperament.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Temperament.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Translation_14c87ec0.o: ../../Source/Core/Configuration/Resources/Models/Translation.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Translation.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ConfigurationResourceCollection_f38be158.o: ../../Source/Core/Configuration/Resources/ConfigurationResourceCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ConfigurationResourceCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ArpeggiatorsCollection_f7d16cec.o: ../../Source/Core/Configuration/Resources/ArpeggiatorsCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ArpeggiatorsCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ChordsCollection_a3d7c529.o: ../../Source/Core/Configuration/Resources/ChordsCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ChordsCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ColourSchemesCollection_bf9a8ab6.o: ../../Source/Core/Configuration/Resources/ColourSchemesCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ColourSchemesCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HotkeySchemesCollection_1a3a9150.o: ../../Source/Core/Configuration/Resources/HotkeySchemesCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HotkeySchemesCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeyboardMappingsCollection_fbfdc47e.o: ../../Source/Core/Configuration/Resources/KeyboardMappingsCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeyboardMappingsCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MetersCollection_5b5e465c.o: ../../Source/Core/Configuration/Resources/MetersCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MetersCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ScalesCollection_573d8e7b.o: ../../Source/Core/Configuration/Resources/ScalesCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ScalesCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TemperamentsCollection_72fe2fa7.o: ../../Source/Core/Configuration/Resources/TemperamentsCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TemperamentsCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TranslationsCollection_8de586f4.o: ../../Source/Core/Configuration/Resources/TranslationsCollection.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TranslationsCollection.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Config_db7b8b0c.o: ../../Source/Core/Configuration/Config.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Config.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UserInterfaceFlags_6a384243.o: ../../Source/Core/Configuration/UserInterfaceFlags.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UserInterfaceFlags.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteActionsProvider_5f29070.o: ../../Source/Core/CommandPalette/CommandPaletteActionsProvider.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteActionsProvider.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteCommonActions_8c32d834.o: ../../Source/Core/CommandPalette/CommandPaletteCommonActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteCommonActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteChordConstructor_f036fca6.o: ../../Source/Core/CommandPalette/CommandPaletteChordConstructor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteChordConstructor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteMoveNotesMenu_a5c6c811.o: ../../Source/Core/CommandPalette/CommandPaletteMoveNotesMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteMoveNotesMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteProjectsList_341ccf60.o: ../../Source/Core/CommandPalette/CommandPaletteProjectsList.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteProjectsList.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPaletteTimelineEvents_2f77aa22.o: ../../Source/Core/CommandPalette/CommandPaletteTimelineEvents.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPaletteTimelineEvents.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MarkovModel_f119297.o: ../../Source/Core/Midi/Models/MarkovModel.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MarkovModel.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/GeneratedSequenceBuilder_4df1380d.o: ../../Source/Core/Midi/Patterns/Modifiers/GeneratedSequenceBuilder.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling GeneratedSequenceBuilder.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Clip_5929fe7f.o: ../../Source/Core/Midi/Patterns/Clip.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Clip.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Pattern_a3a86b8b.o: ../../Source/Core/Midi/Patterns/Pattern.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Pattern.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationEvent_8fa9bdd9.o: ../../Source/Core/Midi/Sequences/Events/AnnotationEvent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationEvent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationEvent_5ea238f1.o: ../../Source/Core/Midi/Sequences/Events/AutomationEvent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationEvent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignatureEvent_80a740ef.o: ../../Source/Core/Midi/Sequences/Events/KeySignatureEvent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignatureEvent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiEvent_cfd604e7.o: ../../Source/Core/Midi/Sequences/Events/MidiEvent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiEvent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Note_42fe2f4e.o: ../../Source/Core/Midi/Sequences/Events/Note.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Note.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignatureEvent_5ddd998b.o: ../../Source/Core/Midi/Sequences/Events/TimeSignatureEvent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignatureEvent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationsSequence_1997bf8b.o: ../../Source/Core/Midi/Sequences/AnnotationsSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationsSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationSequence_84d9de3c.o: ../../Source/Core/Midi/Sequences/AutomationSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignaturesSequence_6a59f1a1.o: ../../Source/Core/Midi/Sequences/KeySignaturesSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignaturesSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiSequence_310d4486.o: ../../Source/Core/Midi/Sequences/MidiSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoSequence_e11a82f0.o: ../../Source/Core/Midi/Sequences/PianoSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignaturesSequence_5fa7c98d.o: ../../Source/Core/Midi/Sequences/TimeSignaturesSequence.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignaturesSequence.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignaturesAggregator_b0273fd5.o: ../../Source/Core/Midi/Sequences/TimeSignaturesAggregator.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignaturesAggregator.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiTrack_6604020d.o: ../../Source/Core/Midi/MidiTrack.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiTrack.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BackendRequest_7a512d9e.o: ../../Source/Core/Network/Requests/BackendRequest.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling BackendRequest.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UserConfigSyncThread_281a0595.o: ../../Source/Core/Network/Requests/UserConfigSyncThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UserConfigSyncThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectCloneThread_838580b1.o: ../../Source/Core/Network/Requests/ProjectCloneThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectCloneThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectDeleteThread_df81aeb5.o: ../../Source/Core/Network/Requests/ProjectDeleteThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectDeleteThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionsSyncHelpers_6a382a95.o: ../../Source/Core/Network/Requests/RevisionsSyncHelpers.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionsSyncHelpers.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionsSyncThread_7ea15884.o: ../../Source/Core/Network/Requests/RevisionsSyncThread.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionsSyncThread.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectSyncService_904c332a.o: ../../Source/Core/Network/Services/ProjectSyncService.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectSyncService.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ResourceSyncService_3cb65bad.o: ../../Source/Core/Network/Services/ResourceSyncService.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ResourceSyncService.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SessionService_7b0612a8.o: ../../Source/Core/Network/Services/SessionService.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SessionService.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NetworkServices_34098b24.o: ../../Source/Core/Network/NetworkServices.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NetworkServices.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Autosaver_8ecb1540.o: ../../Source/Core/Serialization/Autosaver.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Autosaver.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Document_25ea426b.o: ../../Source/Core/Serialization/Document.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Document.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DocumentHelpers_16095e24.o: ../../Source/Core/Serialization/DocumentHelpers.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DocumentHelpers.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SerializedData_9265d6de.o: ../../Source/Core/Serialization/SerializedData.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SerializedData.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BinarySerializer_c8c2cac3.o: ../../Source/Core/Serialization/BinarySerializer.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling BinarySerializer.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/JsonSerializer_97d7162a.o: ../../Source/Core/Serialization/JsonSerializer.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling JsonSerializer.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/XmlSerializer_489b3c03.o: ../../Source/Core/Serialization/XmlSerializer.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling XmlSerializer.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationTrackNode_e0dff3f6.o: ../../Source/Core/Tree/AutomationTrackNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationTrackNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentNode_69832033.o: ../../Source/Core/Tree/InstrumentNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiTrackNode_12dce26c.o: ../../Source/Core/Tree/MidiTrackNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiTrackNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/OrchestraPitNode_9ee364ba.o: ../../Source/Core/Tree/OrchestraPitNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling OrchestraPitNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternEditorNode_ffd5345f.o: ../../Source/Core/Tree/PatternEditorNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternEditorNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoTrackNode_f7a15ace.o: ../../Source/Core/Tree/PianoTrackNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoTrackNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectMetadata_8da17f48.o: ../../Source/Core/Tree/ProjectMetadata.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectMetadata.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectTimeline_9655ff5a.o: ../../Source/Core/Tree/ProjectTimeline.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectTimeline.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectNode_8b4c229b.o: ../../Source/Core/Tree/ProjectNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RootNode_a3140dee.o: ../../Source/Core/Tree/RootNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RootNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SettingsNode_1b17d5af.o: ../../Source/Core/Tree/SettingsNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SettingsNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackGroupNode_96578b40.o: ../../Source/Core/Tree/TrackGroupNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TrackGroupNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TreeNode_364484aa.o: ../../Source/Core/Tree/TreeNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TreeNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TreeNodeSerializer_1d017f1c.o: ../../Source/Core/Tree/TreeNodeSerializer.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TreeNodeSerializer.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControlNode_a601d931.o: ../../Source/Core/Tree/VersionControlNode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControlNode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationEventActions_e2dc4268.o: ../../Source/Core/Undo/Actions/AnnotationEventActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationEventActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationTrackActions_7e56b4ff.o: ../../Source/Core/Undo/Actions/AutomationTrackActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationTrackActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationEventActions_ba8f9c50.o: ../../Source/Core/Undo/Actions/AutomationEventActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationEventActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignatureEventActions_3b0ee412.o: ../../Source/Core/Undo/Actions/KeySignatureEventActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignatureEventActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiTrackActions_47b06bc9.o: ../../Source/Core/Undo/Actions/MidiTrackActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MidiTrackActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NoteActions_b5a2e99f.o: ../../Source/Core/Undo/Actions/NoteActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NoteActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternActions_60a33363.o: ../../Source/Core/Undo/Actions/PatternActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoTrackActions_78338acf.o: ../../Source/Core/Undo/Actions/PianoTrackActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoTrackActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectMetadataActions_5f57158b.o: ../../Source/Core/Undo/Actions/ProjectMetadataActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectMetadataActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignatureEventActions_c6f6be42.o: ../../Source/Core/Undo/Actions/TimeSignatureEventActions.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignatureEventActions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UndoStack_c8cfe6ea.o: ../../Source/Core/Undo/UndoStack.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UndoStack.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationTrackDiffLogic_d3a28db5.o: ../../Source/Core/VCS/DiffLogic/AutomationTrackDiffLogic.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationTrackDiffLogic.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DiffLogic_e39316b3.o: ../../Source/Core/VCS/DiffLogic/DiffLogic.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DiffLogic.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternDiffHelpers_2a43df40.o: ../../Source/Core/VCS/DiffLogic/PatternDiffHelpers.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternDiffHelpers.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoTrackDiffLogic_1fe33611.o: ../../Source/Core/VCS/DiffLogic/PianoTrackDiffLogic.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoTrackDiffLogic.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectInfoDiffLogic_85d6d922.o: ../../Source/Core/VCS/DiffLogic/ProjectInfoDiffLogic.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectInfoDiffLogic.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectTimelineDiffLogic_dd926f6f.o: ../../Source/Core/VCS/DiffLogic/ProjectTimelineDiffLogic.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectTimelineDiffLogic.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Delta_dc1eed28.o: ../../Source/Core/VCS/Delta.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Delta.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Diff_3af4c61f.o: ../../Source/Core/VCS/Diff.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Diff.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Head_fe3c227a.o: ../../Source/Core/VCS/Head.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Head.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RemoteCache_d9eaca0c.o: ../../Source/Core/VCS/RemoteCache.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RemoteCache.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Revision_ddbb1c75.o: ../../Source/Core/VCS/Revision.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Revision.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionItem_7e6e5a28.o: ../../Source/Core/VCS/RevisionItem.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionItem.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Snapshot_f0be1dde.o: ../../Source/Core/VCS/Snapshot.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Snapshot.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/StashesRepository_bb52fdfd.o: ../../Source/Core/VCS/StashesRepository.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling StashesRepository.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControl_bc67ed3f.o: ../../Source/Core/VCS/VersionControl.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControl.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NavigationHistory_39a99bf.o: ../../Source/Core/Workspace/NavigationHistory.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NavigationHistory.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RecentProjectInfo_9bf049eb.o: ../../Source/Core/Workspace/RecentProjectInfo.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RecentProjectInfo.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SyncedConfigurationInfo_f19402c9.o: ../../Source/Core/Workspace/SyncedConfigurationInfo.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SyncedConfigurationInfo.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UserSessionInfo_61ea4378.o: ../../Source/Core/Workspace/UserSessionInfo.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UserSessionInfo.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UserProfile_63ae89bd.o: ../../Source/Core/Workspace/UserProfile.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UserProfile.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Workspace_e70d39f4.o: ../../Source/Core/Workspace/Workspace.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Workspace.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/App_9f51319a.o: ../../Source/Core/App.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling App.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ColourButton_d92c95b0.o: ../../Source/UI/Common/ColourButton.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ColourButton.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ColourSwatches_e2a4628.o: ../../Source/UI/Common/ColourSwatches.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ColourSwatches.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandIDs_ca65c4df.o: ../../Source/UI/Common/CommandIDs.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandIDs.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ColourIDs_78db4164.o: ../../Source/UI/Common/ColourIDs.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ColourIDs.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DraggingListBoxComponent_34f40031.o: ../../Source/UI/Common/DraggingListBoxComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DraggingListBoxComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySelector_58be6196.o: ../../Source/UI/Common/KeySelector.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySelector.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MobileComboBox_bdac55f1.o: ../../Source/UI/Common/MobileComboBox.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MobileComboBox.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ModeIndicatorComponent_7338ae83.o: ../../Source/UI/Common/ModeIndicatorComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ModeIndicatorComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PlayButton_38579458.o: ../../Source/UI/Common/PlayButton.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PlayButton.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginWindow_66751815.o: ../../Source/UI/Common/PluginWindow.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PluginWindow.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RadioButton_45b0c9c5.o: ../../Source/UI/Common/RadioButton.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RadioButton.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ScaleEditor_6bc10d0f.o: ../../Source/UI/Common/ScaleEditor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ScaleEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SpectralLogo_f6755a41.o: ../../Source/UI/Common/SpectralLogo.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SpectralLogo.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TransportControlComponent_4d74e1.o: ../../Source/UI/Common/TransportControlComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TransportControlComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ViewportFitProxyComponent_a93fb792.o: ../../Source/UI/Common/ViewportFitProxyComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ViewportFitProxyComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DialogBase_ff1ce7b9.o: ../../Source/UI/Dialogs/DialogBase.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DialogBase.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationDialog_bb76a597.o: ../../Source/UI/Dialogs/AnnotationDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignatureDialog_b4559c41.o: ../../Source/UI/Dialogs/KeySignatureDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignatureDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ModalDialogConfirmation_23a5c174.o: ../../Source/UI/Dialogs/ModalDialogConfirmation.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ModalDialogConfirmation.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ModalDialogInput_6af917b5.o: ../../Source/UI/Dialogs/ModalDialogInput.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ModalDialogInput.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RenderDialog_d54ea4be.o: ../../Source/UI/Dialogs/RenderDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RenderDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TempoDialog_19dcad8d.o: ../../Source/UI/Dialogs/TempoDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TempoDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignatureDialog_7d6669dd.o: ../../Source/UI/Dialogs/TimeSignatureDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignatureDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackPropertiesDialog_5e178150.o: ../../Source/UI/Dialogs/TrackPropertiesDialog.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TrackPropertiesDialog.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Headline_2606435d.o: ../../Source/UI/Headline/Headline.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Headline.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HeadlineDropdown_494f430e.o: ../../Source/UI/Headline/HeadlineDropdown.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HeadlineDropdown.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HeadlineItem_cd7bcd10.o: ../../Source/UI/Headline/HeadlineItem.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HeadlineItem.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HeadlineContextMenuController_eb2fb3d7.o: ../../Source/UI/Headline/HeadlineContextMenuController.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HeadlineContextMenuController.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MultiTouchController_63afb603.o: ../../Source/UI/Input/MultiTouchController.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MultiTouchController.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MenuItemComponent_2eff5284.o: ../../Source/UI/Menus/Base/MenuItemComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MenuItemComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MenuPanel_ee874d5e.o: ../../Source/UI/Menus/Base/MenuPanel.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MenuPanel.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioPluginSelectionMenu_3e54c8bc.o: ../../Source/UI/Menus/SelectionMenus/AudioPluginSelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioPluginSelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentNodeSelectionMenu_d61c1e72.o: ../../Source/UI/Menus/SelectionMenus/InstrumentNodeSelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentNodeSelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternRollSelectionMenu_1f7a27b8.o: ../../Source/UI/Menus/SelectionMenus/PatternRollSelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternRollSelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoRollSelectionMenu_69b358df.o: ../../Source/UI/Menus/SelectionMenus/PianoRollSelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoRollSelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControlHistorySelectionMenu_55cc6e76.o: ../../Source/UI/Menus/SelectionMenus/VersionControlHistorySelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControlHistorySelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControlStageSelectionMenu_d66783cc.o: ../../Source/UI/Menus/SelectionMenus/VersionControlStageSelectionMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControlStageSelectionMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentMenu_4fd005bd.o: ../../Source/UI/Menus/InstrumentMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ClipMenu_13ec0da6.o: ../../Source/UI/Menus/ClipMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ClipMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/OrchestraPitMenu_2065d304.o: ../../Source/UI/Menus/OrchestraPitMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling OrchestraPitMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternsMenu_1f8f0d39.o: ../../Source/UI/Menus/PatternsMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternsMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectMenu_5ab725eb.o: ../../Source/UI/Menus/ProjectMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimelineMenu_2c071c97.o: ../../Source/UI/Menus/TimelineMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimelineMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControlMenu_cb7aa03b.o: ../../Source/UI/Menus/VersionControlMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControlMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/WorkspaceMenu_25163be7.o: ../../Source/UI/Menus/WorkspaceMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling WorkspaceMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Dashboard_81cfc8dc.o: ../../Source/UI/Pages/Dashboard/Dashboard.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Dashboard.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DashboardMenu_bcc0f5b.o: ../../Source/UI/Pages/Dashboard/DashboardMenu.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DashboardMenu.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioPluginEditorPage_d260a64d.o: ../../Source/UI/Pages/Instruments/Editor/AudioPluginEditorPage.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioPluginEditorPage.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentEditor_e7548c16.o: ../../Source/UI/Pages/Instruments/Editor/InstrumentEditor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentEditorConnector_813d7c21.o: ../../Source/UI/Pages/Instruments/Editor/InstrumentEditorConnector.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentEditorConnector.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentComponent_f2b63e3e.o: ../../Source/UI/Pages/Instruments/Editor/InstrumentComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentEditorPin_387238a9.o: ../../Source/UI/Pages/Instruments/Editor/InstrumentEditorPin.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentEditorPin.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeyboardMappingPage_6ce5b77e.o: ../../Source/UI/Pages/Instruments/Editor/KeyboardMappingPage.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeyboardMappingPage.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioPluginsListComponent_27b60455.o: ../../Source/UI/Pages/Instruments/AudioPluginsListComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioPluginsListComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentsListComponent_2905dadd.o: ../../Source/UI/Pages/Instruments/InstrumentsListComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling InstrumentsListComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/OrchestraPitPage_52882f47.o: ../../Source/UI/Pages/Instruments/OrchestraPitPage.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling OrchestraPitPage.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectPage_f686b2d5.o: ../../Source/UI/Pages/Project/ProjectPage.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectPage.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioSettings_716d894.o: ../../Source/UI/Pages/Settings/AudioSettings.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AudioSettings.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ComponentsList_fad5fa03.o: ../../Source/UI/Pages/Settings/ComponentsList.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ComponentsList.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SettingsFrameWrapper_27c0b958.o: ../../Source/UI/Pages/Settings/SettingsFrameWrapper.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SettingsFrameWrapper.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SettingsPage_ab9efe01.o: ../../Source/UI/Pages/Settings/SettingsPage.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SettingsPage.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SyncSettings_7b017e8d.o: ../../Source/UI/Pages/Settings/SyncSettings.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SyncSettings.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SyncSettingsItem_6f05f040.o: ../../Source/UI/Pages/Settings/SyncSettingsItem.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SyncSettingsItem.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ThemeSettings_1f7e5e07.o: ../../Source/UI/Pages/Settings/ThemeSettings.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ThemeSettings.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ThemeSettingsItem_c2b282ba.o: ../../Source/UI/Pages/Settings/ThemeSettingsItem.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ThemeSettingsItem.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TranslationSettings_f4a7f26f.o: ../../Source/UI/Pages/Settings/TranslationSettings.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TranslationSettings.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TranslationSettingsItem_6aba322.o: ../../Source/UI/Pages/Settings/TranslationSettingsItem.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TranslationSettingsItem.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UserInterfaceSettings_8b19486c.o: ../../Source/UI/Pages/Settings/UserInterfaceSettings.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling UserInterfaceSettings.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HistoryComponent_115e47f9.o: ../../Source/UI/Pages/VCS/HistoryComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HistoryComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionComponent_51e2497c.o: ../../Source/UI/Pages/VCS/RevisionComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionConnectorComponent_a2024cdb.o: ../../Source/UI/Pages/VCS/RevisionConnectorComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionConnectorComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionItemComponent_8654a029.o: ../../Source/UI/Pages/VCS/RevisionItemComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionItemComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionTooltipComponent_c893ee65.o: ../../Source/UI/Pages/VCS/RevisionTooltipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionTooltipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RevisionTreeComponent_2b8f217e.o: ../../Source/UI/Pages/VCS/RevisionTreeComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RevisionTreeComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/StageComponent_f36288f.o: ../../Source/UI/Pages/VCS/StageComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling StageComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VersionControlEditor_c12aa262.o: ../../Source/UI/Pages/VCS/VersionControlEditor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VersionControlEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommandPalette_cdcff526.o: ../../Source/UI/Popups/CommandPalette.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CommandPalette.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ArpPreviewTool_98f46997.o: ../../Source/UI/Popups/ArpPreviewTool.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ArpPreviewTool.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ChordPreviewTool_422991ba.o: ../../Source/UI/Popups/ChordPreviewTool.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ChordPreviewTool.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RescalePreviewTool_6e22f57f.o: ../../Source/UI/Popups/RescalePreviewTool.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RescalePreviewTool.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ModalCallout_e0f2fbf9.o: ../../Source/UI/Popups/ModalCallout.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ModalCallout.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PopupButton_5c5e0092.o: ../../Source/UI/Popups/PopupButton.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PopupButton.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PopupCustomButton_6d33e2a3.o: ../../Source/UI/Popups/PopupCustomButton.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PopupCustomButton.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProgressTooltip_f470232a.o: ../../Source/UI/Popups/ProgressTooltip.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProgressTooltip.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TooltipContainer_52ddacf4.o: ../../Source/UI/Popups/TooltipContainer.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TooltipContainer.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MarkovEditorComponent_5beab128.o: ../../Source/UI/Sequencer/MarkovEditor/MarkovEditorComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MarkovEditorComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationEditor_10bbc76.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationEditor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationCurveHelper_d482275e.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationCurveHelper.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationCurveHelper.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationCurveEventComponent_25e511b3.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationCurveEventComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationCurveEventComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationCurveEventsConnector_1577264e.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationCurveEventsConnector.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationCurveEventsConnector.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationStepEventComponent_5a4a4178.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationStepEventComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationStepEventComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationStepEventsConnector_6db7ef29.o: ../../Source/UI/Sequencer/EditorPanels/AutomationEditor/AutomationStepEventsConnector.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationStepEventsConnector.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/VelocityEditor_10f56f76.o: ../../Source/UI/Sequencer/EditorPanels/VelocityEditor/VelocityEditor.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling VelocityEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/EditorPanelsScroller_377f2319.o: ../../Source/UI/Sequencer/EditorPanels/EditorPanelsScroller.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling EditorPanelsScroller.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HeaderSelectionIndicator_5aed2562.o: ../../Source/UI/Sequencer/Header/HeaderSelectionIndicator.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HeaderSelectionIndicator.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RollHeader_b1badd3c.o: ../../Source/UI/Sequencer/Header/RollHeader.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RollHeader.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Playhead_49aa3d26.o: ../../Source/UI/Sequencer/Header/Playhead.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Playhead.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CutPointMark_e432a7df.o: ../../Source/UI/Sequencer/Helpers/CutPointMark.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling CutPointMark.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RollExpandMark_91f57428.o: ../../Source/UI/Sequencer/Helpers/RollExpandMark.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RollExpandMark.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KnifeToolHelper_d68a471.o: ../../Source/UI/Sequencer/Helpers/KnifeToolHelper.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KnifeToolHelper.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MergingEventsConnector_d1b12a43.o: ../../Source/UI/Sequencer/Helpers/MergingEventsConnector.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MergingEventsConnector.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimelineWarningMarker_6d5c36fb.o: ../../Source/UI/Sequencer/Helpers/TimelineWarningMarker.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimelineWarningMarker.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternOperations_aae46f62.o: ../../Source/UI/Sequencer/Helpers/PatternOperations.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternOperations.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SequencerOperations_4fa1bea3.o: ../../Source/UI/Sequencer/Helpers/SequencerOperations.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SequencerOperations.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationCurveClipComponent_2806cdb1.o: ../../Source/UI/Sequencer/PatternRoll/AutomationCurveClipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationCurveClipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AutomationStepsClipComponent_ae8db279.o: ../../Source/UI/Sequencer/PatternRoll/AutomationStepsClipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AutomationStepsClipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoClipComponent_726e7f60.o: ../../Source/UI/Sequencer/PatternRoll/PianoClipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoClipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ClipComponent_3c63e97b.o: ../../Source/UI/Sequencer/PatternRoll/ClipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ClipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/DummyClipComponent_76f3c1e1.o: ../../Source/UI/Sequencer/PatternRoll/DummyClipComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling DummyClipComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PatternRoll_9707f85b.o: ../../Source/UI/Sequencer/PatternRoll/PatternRoll.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PatternRoll.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HighlightingScheme_959e38f6.o: ../../Source/UI/Sequencer/PianoRoll/HighlightingScheme.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HighlightingScheme.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NoteComponent_465c17d2.o: ../../Source/UI/Sequencer/PianoRoll/NoteComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NoteComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NoteNameGuidesBar_93845a26.o: ../../Source/UI/Sequencer/PianoRoll/NoteNameGuidesBar.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NoteNameGuidesBar.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NoteResizerLeft_c3d11e3a.o: ../../Source/UI/Sequencer/PianoRoll/NoteResizerLeft.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NoteResizerLeft.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/NoteResizerRight_f3a02f93.o: ../../Source/UI/Sequencer/PianoRoll/NoteResizerRight.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling NoteResizerRight.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoRoll_c125538d.o: ../../Source/UI/Sequencer/PianoRoll/PianoRoll.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoRoll.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SequencerSidebarLeft_1fad65fa.o: ../../Source/UI/Sequencer/Sidebars/SequencerSidebarLeft.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SequencerSidebarLeft.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SequencerSidebarRight_134cdfd3.o: ../../Source/UI/Sequencer/Sidebars/SequencerSidebarRight.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SequencerSidebarRight.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/WaveformAudioMonitorComponent_f44a773e.o: ../../Source/UI/Sequencer/Sidebars/WaveformAudioMonitorComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling WaveformAudioMonitorComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationLargeComponent_d95ee3c1.o: ../../Source/UI/Sequencer/MiniMaps/AnnotationsMap/AnnotationLargeComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationLargeComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationSmallComponent_f4fc5575.o: ../../Source/UI/Sequencer/MiniMaps/AnnotationsMap/AnnotationSmallComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationSmallComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AnnotationsProjectMap_e8c59661.o: ../../Source/UI/Sequencer/MiniMaps/AnnotationsMap/AnnotationsProjectMap.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling AnnotationsProjectMap.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignatureLargeComponent_7ce9b141.o: ../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap/KeySignatureLargeComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignatureLargeComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignatureSmallComponent_988722f5.o: ../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap/KeySignatureSmallComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignatureSmallComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeySignaturesProjectMap_4269b8e1.o: ../../Source/UI/Sequencer/MiniMaps/KeySignaturesMap/KeySignaturesProjectMap.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling KeySignaturesProjectMap.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PianoProjectMap_b13b64c1.o: ../../Source/UI/Sequencer/MiniMaps/PianoMap/PianoProjectMap.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling PianoProjectMap.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignatureLargeComponent_9bda06b.o: ../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap/TimeSignatureLargeComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignatureLargeComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignatureSmallComponent_255b121f.o: ../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap/TimeSignatureSmallComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignatureSmallComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeSignaturesProjectMap_407e29f7.o: ../../Source/UI/Sequencer/MiniMaps/TimeSignaturesMap/TimeSignaturesProjectMap.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling TimeSignaturesProjectMap.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectMapsScroller_c98b46a3.o: ../../Source/UI/Sequencer/MiniMaps/ProjectMapsScroller.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ProjectMapsScroller.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RollBase_a5b0a008.o: ../../Source/UI/Sequencer/RollBase.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RollBase.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RollEditMode_11c8f104.o: ../../Source/UI/Sequencer/RollEditMode.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RollEditMode.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/LassoListeners_6bea92bf.o: ../../Source/UI/Sequencer/LassoListeners.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling LassoListeners.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RollChildComponentBase_d38a0ee9.o: ../../Source/UI/Sequencer/RollChildComponentBase.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling RollChildComponentBase.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SelectionComponent_9dff102b.o: ../../Source/UI/Sequencer/SelectionComponent.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SelectionComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SequencerLayout_58e2f98b.o: ../../Source/UI/Sequencer/SequencerLayout.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling SequencerLayout.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/HelioTheme_d6ec9067.o: ../../Source/UI/Themes/HelioTheme.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling HelioTheme.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Icons_7879bcb1.o: ../../Source/UI/Themes/Icons.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Icons.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ViewportKineticSlider_45304cab.o: ../../Source/UI/Themes/ViewportKineticSlider.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling ViewportKineticSlider.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MainLayout_4f58d3f.o: ../../Source/UI/MainLayout.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling MainLayout.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Common_6ff75bf4.o: ../../Source/Common.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling Common.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BinaryData_7821001c.o: ../Projucer/JuceLibraryCode/BinaryData.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling BinaryData.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_basics_68629202.o: ../Projucer/JuceLibraryCode/include_juce_audio_basics.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_devices_477c5a4a.o: ../Projucer/JuceLibraryCode/include_juce_audio_devices.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_devices.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_formats_fa635d49.o: ../Projucer/JuceLibraryCode/include_juce_audio_formats.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_formats.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_6c50941e.o: ../Projucer/JuceLibraryCode/include_juce_audio_processors.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_processors.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_ara_668730af.o: ../Projucer/JuceLibraryCode/include_juce_audio_processors_ara.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_processors_ara.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_lv2_libs_fc0f5b50.o: ../Projucer/JuceLibraryCode/include_juce_audio_processors_lv2_libs.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_audio_processors_lv2_libs.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_9b124993.o: ../Projucer/JuceLibraryCode/include_juce_core.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_core.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_CompilationTime_ce9235e4.o: ../Projucer/JuceLibraryCode/include_juce_core_CompilationTime.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_core_CompilationTime.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_data_structures_eb02bd2b.o: ../Projucer/JuceLibraryCode/include_juce_data_structures.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_data_structures.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_events_23f77a4d.o: ../Projucer/JuceLibraryCode/include_juce_events.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_events.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_82dd76ff.o: ../Projucer/JuceLibraryCode/include_juce_graphics.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_graphics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_Harfbuzz_774084ea.o: ../Projucer/JuceLibraryCode/include_juce_graphics_Harfbuzz.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_graphics_Harfbuzz.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_Sheenbidi_1ea0f505.o: ../Projucer/JuceLibraryCode/include_juce_graphics_Sheenbidi.c
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_graphics_Sheenbidi.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_basics_d3ae9f3d.o: ../Projucer/JuceLibraryCode/include_juce_gui_basics.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_gui_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_extra_3bdb3d62.o: ../Projucer/JuceLibraryCode/include_juce_gui_extra.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_gui_extra.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_opengl_1ea9a6e3.o: ../Projucer/JuceLibraryCode/include_juce_opengl.cpp
	-$(V_AT)mkdir -p $(@D)
	@echo "Compiling include_juce_opengl.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_APP) $(JUCE_CFLAGS_APP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/execinfo.cmd:
	-$(V_AT)mkdir -p $(@D)
	-@if [ -z "$(V_AT)" ]; then echo "Checking if we need to link libexecinfo"; fi
	$(V_AT)printf "int main() { return 0; }" | $(CXX) -x c++ -o $(@D)/execinfo.x -lexecinfo - >/dev/null 2>&1 && printf -- "-lexecinfo" > "$@" || touch "$@"

$(JUCE_OBJDIR)/cxxfs.cmd:
	-$(V_AT)mkdir -p $(@D)
	-@if [ -z "$(V_AT)" ]; then echo "Checking if we need to link stdc++fs"; fi
	$(V_AT)printf "int main() { return 0; }" | $(CXX) -x c++ -o $(@D)/cxxfs.x -lstdc++fs - >/dev/null 2>&1 && printf -- "-lstdc++fs" > "$@" || touch "$@"

clean:
	@echo Cleaning Helio
	$(V_AT)$(CLEANCMD)

strip:
	@echo Stripping Helio
	-$(V_AT)$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(JUCE_TARGET_APP)

-include $(OBJECTS_APP:%.o=%.d)

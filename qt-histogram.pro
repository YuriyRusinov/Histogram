# main project file

TEMPLATE = subdirs

# Directories
SUBDIRS += \
          src \
          app

include(./qt_hist.conf)

unix{
    CONFIG_NAME_FILE = ./install_prefix.conf

    CURRENT_STRING = $$sprintf("printf %1OBJP_PREFIX=%2%1 > %3", $$LITERAL_QUOTE, $$OBJP_PREFIX, $$CONFIG_NAME_FILE)
    system($$CURRENT_STRING)
}

#RESOURCES = ./src/icons/objp_icon_set.qrc

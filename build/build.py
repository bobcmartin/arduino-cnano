__author__ = 'lharing'

import os
import json
import shutil
import hashlib


version = "1.0.0"
archive_file_name = "arduino-cnano-" + version + ".zip"
archive_file_url = "https://github.com/lharing/arduino-cnano/releases/download/" + version + "/" + archive_file_name


def update_package_index():
    print("Updating package index")
    # load package template
    package_template_file = open("package_template.json")
    package_template = json.load(package_template_file)
    package_template_file.close()

    checksum = hash_archive(archive_file_name)

    # update package fields
    package_template['platforms'][0]['version'] = version
    package_template['platforms'][0]['url'] = archive_file_url
    package_template['platforms'][0]['archiveFileName'] = archive_file_name
    package_template['platforms'][0]['size'] = os.path.getsize(archive_file_name)
    package_template['platforms'][0]['checksum'] = "SHA-256:" + checksum

    # load package index
    package_index_file = open("../package_cnano_index.json", "r+")
    package_index = json.load(package_index_file)

    # add new entry to package index
    package_index['packages'].append(package_template)
    package_index_file.seek(0)
    package_index_file.truncate()
    json.dump(package_index, package_index_file, indent=4, sort_keys=True)
    package_index_file.close()


def create_archive():
    print("Creating package archive {}".format(archive_file_name))
    shutil.make_archive(archive_file_name.rstrip('.zip'), "zip", "../CuriosityNanoPackage")


def hash_archive(file_name):
    file = open(file_name, "rb")
    sha256 = hashlib.sha256()
    sha256.update(file.read())
    digest = sha256.hexdigest()
    return digest

if __name__ == '__main__':
    create_archive()
    update_package_index()
    print("New release {} ready".format(version))

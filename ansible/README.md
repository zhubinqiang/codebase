# ansible

## update ansible.cfg
```sh
cp /etc/ansible/ansible.cfg ~/.ansible.cfg
```

update ~/.ansible.cfg
```ini
[defaults]
interpreter_python = /usr/bin/python3
inventory          = ~/.ansible/hosts
# remote_tmp     = /tmp/.ansible-${USER}/tmp
# stdout_callback = json
# bin_ansible_callbacks = True
stdout_callback = yaml
```

refer to /etc/ansible/hosts to update  ~/.ansible/hosts

```ini
[one]
192.168.1.1 ansible_connection=ssh ansible_ssh_user=media ansible_ssh_pass=media ansible_become_pass=media

[two]
192.168.1.2 ansible_connection=ssh ansible_ssh_user=root ansible_ssh_pass=123456
192.168.1.4 ansible_connection=ssh ansible_ssh_user=root ansible_ssh_pass=123456
```


```sh
## single
ansible one -m fetch -a 'src=/tmp/a.txt dest=/dev/shm/from-remote.txt flat=yes'

## playbook
ansible-playbook addition.yml -vv

## output as yaml format
ANSIBLE_STDOUT_CALLBACK=yaml ansible-playbook addition.yml -vv
```

addition.yml
```yml
---
  - name: Use minimal recipe
    import_playbook: "ubuntu-base.yml"

  - hosts: all

    vars:
      - ansible_python_interpreter: /usr/bin/python3
      - user: media

    tasks:

      # - name: Remove sources.list
      #   file:
      #     path: /etc/apt/sources.list
      #     state: absent


      # # state: touch | directory | absent
      - name: "create WS"
        file:
          path: /home/{{ user }}/WS
          state: directory
          owner: "{{ user }}"
          group: "{{ user }}"
          mode: 0755

      - name: install nvim
        shell:
          chdir: /dev/shm/
          cmd: |
            ls
            pwd
            cd /tmp
            ls
```


ubuntu-base.yml
```yml
---
  - hosts: all

    vars:
      - ansible_python_interpreter: /usr/bin/python3

    environment:
      http_proxy: "http://proxy.example.com:913"
      https_proxy: "http://proxy.example.com:913"
      no_proxy: "127.0.0.1, example.com,.example.com,192.168.0.0/16,localhost,.local,127.0.0.0/8"

    tasks:
      - name: "apt install"
        become: yes
        apt:
          name: [
          'expect',
          'tmux'
          ]
          state: present
          update_cache: yes
          force_apt_get: yes
```



